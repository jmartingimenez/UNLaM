$(document).ready(function() {
    var table = $('#tablaPaginada').DataTable({"sPaginationType": "full_numbers"}); 
 
    $('#tablaPaginada tbody').on( 'click', 'tr', function () {
        if ( $(this).hasClass('selected') ) {
            $(this).removeClass('selected');
        }
        else {
            table.$('tr.selected').removeClass('selected');
            $(this).addClass('selected');
        }
    } );
 
    $('#button').click( function () {
        table.row('.selected').remove().draw( false );
    } );  


    var table2 = $('#tablaPaginada2').DataTable({"sPaginationType": "full_numbers"}); 
 
    $('#tablaPaginada2 tbody').on( 'click', 'tr', function () {
        if ( $(this).hasClass('selected') ) {
            $(this).removeClass('selected');
        }
        else {
            table2.$('tr.selected').removeClass('selected');
            $(this).addClass('selected');
        }
    } );
 
    $('#button2').click( function () {
        table2.row('.selected').remove().draw( false );
    } );  



} );
