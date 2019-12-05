/* Dependencies */
require('dotenv').load();

/* Environment constants for building */
const environment = 'dev';
// const environment = 'prod';

var gulp = require('gulp'),
    argv = require('yargs').argv,
    runSequence = require('run-sequence'),
    config = require('./app_config.js'),
    fs = require('fs'),
    ngConfig = require('gulp-ng-config'),
    clean = require('gulp-clean'),
    jshint = require('gulp-jshint'),
    htmlhint = require('gulp-htmlhint'),
    concat = require('gulp-concat'),
    uglify = require('gulp-uglify'),
    connect = require('gulp-connect'),
    htmlreplace = require('gulp-html-replace'),
    date = new Date(),
    version = date.getFullYear().toString() +
        (date.getMonth() + 1).toString() +
        date.getDate().toString() +
        date.getHours().toString() +
        date.getMinutes().toString();

/* Clean DIST folder */
gulp.task('clean', function () {
    return gulp.src('dist/*')
                .pipe(clean({
                    force: true
                }));
});

/* Creates config for environment constants */
gulp.task('ng-config', function () {
    fs.writeFileSync('config.json', JSON.stringify(config[environment]));
    return gulp.src('config.json')
                .pipe(
                    ngConfig('app.config', {
                        createModule: false
                    })
                )
                .pipe(gulp.dest('app/'));
});

/* Activate JS flags to detect ERRORS */
gulp.task('jshint', function () {
    gulp.src(['app/**/*.js', '!app/resources/**/*.js'])
        .pipe(jshint('.jshintrc'))
        .pipe(jshint.reporter('default'))
        .pipe(jshint.reporter('fail'));
});

/* Activate HTML flags to detect ERRORS */
gulp.task('htmlhint', function () {
    gulp.src(['app/**/*.html', '!app/resources/**/*.html'])
        .pipe(htmlhint('.htmlhintrc'))
        .pipe(htmlhint.reporter());
});

/* Copy RESOURCES folder */
gulp.task('copy-resources', function () {
    gulp.src('app/resources/**')
        .pipe(gulp.dest('dist/resources'));
});

/* Copy .HTML files */
gulp.task('copy-html', function () {
    gulp.src(['app/**/*.html', '!app/index.html'])
        .pipe(gulp.dest('dist/'));
});

/* Minify and BUNDLE every .JS file in APP */
gulp.task('bundle-js', function () {
    gulp.src(['app/*.js', 'app/**/*.js', '!app/resources/**/*.js'])
        .pipe(concat('bundle.js'))
        //.pipe(uglify())
        .pipe(gulp.dest('dist/'));
});

/* Copy INDEX.HTML and add VERSION to BUNDLE.JS script TAG */
gulp.task('version-js', function () {
    gulp.src('app/index.html')
        .pipe(htmlreplace({
            'js': {
                src: ['bundle.js?v=' + version],
                tpl: '<script src="%s"></script>'
            }
        }))
        .pipe(gulp.dest('dist/'));
});

/* Sequence of tasks to build the DIST folder */
gulp.task('build', function () {
    runSequence(
        'clean',
        'ng-config',
        //'jshint',
        'htmlhint',
        'copy-resources',
        'copy-html',
        'bundle-js',
        'version-js'
    );
});

/* STARTS the server at localhost:8081 */
gulp.task('http-server', function () {
    connect.server({
        root: 'dist',
        port: 8081
    });
});

/* Sets WATCHES to update the changes to the server */
gulp.task('watch', function () {
    gulp.watch('app/resources/**', ['copy-resources'])
    gulp.watch(['app/**/*.html', '!app/index.html'], ['copy-html'])
    gulp.watch(['app/*.js', 'app/**/*.js', '!app/resources/**/*.js'], ['bundle-js'])
    gulp.watch('app/index.html', ['version-js'])
});

/* DEFAULT gulp action */
gulp.task('default', function () {
    runSequence(
        'build',
        'http-server',
        'watch'
    )
});