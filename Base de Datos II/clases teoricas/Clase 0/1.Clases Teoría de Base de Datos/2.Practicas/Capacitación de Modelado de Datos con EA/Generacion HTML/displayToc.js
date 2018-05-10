/*------------------------------------------------------------------- 
Acknowledgment:
This Javascript is a modified version of an original idea by Dieter Bungers. 
The original author's statement is included below:
*********************************************************************
This script is based in part on ideas of Dieter Bungers.
You may copy, modify and use it for any purpose. The only condition is that 
if you publish web pages that use this script you point to its author at a 
suitable place and don't remove this Statement from it.
It's your responsibility to handle possible bugs even if you didn't modify
anything. I cannot promise any support.
Dieter Bungers GMD (www.gmd.de) and infovation (www.infovation.de)
--------------------------------------------------------------------*/

if (navigator.appName.toLowerCase().indexOf("explorer") > -1) {
	var mdi=textSizes[1], sml=textSizes[2];
}
else {
	var mdi=textSizes[3], sml=textSizes[4];
}


function reDisplay(currentNumber,currentIsExpanded) {
	toc.document.open();
	toc.document.write("<html>\n<head>\n<title>ToC</title>\n<link href=\"eacont.css\" rel=stylesheet>\n</head>\n<body>\n<table border=0 cellspacing=1 cellpadding=0>\n<tr>");
	var currentNumArray = currentNumber.split(".");
	var currentLevel = currentNumArray.length-1;
	var scrollY=0, addScroll=true, theHref="", isContentTarget=false;
	for (i=0; i<tocTab.length; i++) {
		thisNumber = tocTab[i][0];
		var isCurrentNumber = (thisNumber == currentNumber);
		if (isCurrentNumber) 
		{
			theHref=tocTab[i][2];
			isContentTarget = (tocTab[i][3] == "true");
		}

		var thisNumArray = thisNumber.split(".");
		var thisLevel = thisNumArray.length-1;
		var toDisplay = true;
		if (thisLevel > 0) {
			for (j=0; j<thisLevel; j++) {
				toDisplay = (j>currentLevel)?false:toDisplay && (thisNumArray[j] == currentNumArray[j]);
			}
		}
		thisIsExpanded = toDisplay && (thisNumArray[thisLevel] == currentNumArray[thisLevel])
		if (currentIsExpanded) {
			toDisplay = toDisplay && (thisLevel<=currentLevel);
			if (isCurrentNumber) thisIsExpanded = false;
		}
		
		if (toDisplay) {
			if (i==0) {
				toc.document.writeln("\n<td class=\"TreeTitle\" colspan=" + (nCols+1) + "><a href=\"javaScript:\parent.reDisplay('" + thisNumber + "'," + thisIsExpanded + ")\" style=\"font-size:" + textSizes[0] + "em;\"><b>" + tocTab[i][1] + "</b></a></td></tr>");
				for (k=0; k<nCols; k++) {
					toc.document.write("<td>&nbsp;</td>");
				}
				toc.document.write("<td width=240>&nbsp;</td></tr>");
				}
			else {
				if (addScroll) scrollY+=((thisLevel<2)?mdi:sml)*25;
				if (isCurrentNumber) addScroll=false;
				var isLeaf = (i==tocTab.length-1) || (thisLevel >= tocTab[i+1][0].split(".").length-1);
				img = (isLeaf)?"leaf":(thisIsExpanded)?"minus":"plus";
				toc.document.writeln("<tr class=\"TreeRow\">");
				for (k=1; k<=thisLevel; k++) {
					toc.document.writeln("<td>&nbsp;</td>");
				}
				toc.document.writeln("<td valign=top><a href=\"javaScript:parent.reDisplay('" + thisNumber + "'," + thisIsExpanded + ");\" ><img src=\"images/" + img + ".gif\" border=0></a></td> <td colspan=" + (nCols-thisLevel) + "><a href=\"javaScript:\parent.reDisplay('" + thisNumber + "'," + thisIsExpanded + ")\" style=\"" + ((thisLevel<=mLevel)?"font-weight:bold;":"") +  " font-size:" + ((thisLevel<=mLevel)?mdi:sml) + "em; \">" + ((showNumbers)?(thisNumber+" "):"") + tocTab[i][1] + "</a></td></tr>");
			}
		}
	}
	toc.document.writeln("</table>\n</body>");
	toc.document.close();
	toc.scroll(0,scrollY);
	
	if (theHref != "") 
		if (isContentTarget) content.document.location.href = theHref;
		else bon.document.location.href = theHref; //content.location.href = theHref;
}