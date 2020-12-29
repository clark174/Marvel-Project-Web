// JavaScript for Name Data Lookup Demo
// Jim Skon, Kenyon College, 2019
var searchType;  // Save serach type here
var indexList; //save the output from the cgi file here.
$(document).ready(function () {
    console.log("start!");
    searchType="Name";
    $("#search-btn").click(getMatches);

    $("#clear").click(clearResults);

    $(".dropdown-menu a").click(function(){
	console.log("pick!"+$(this).text());
	$(this).parents(".dropdown").find(".selection").text($(this).text());
	searchType=$(this).text();
    });
});

// Build output table from comma delimited list
function nameTable(list) {
    var result = '<table class="w3-table-all w3-hoverable" border="2"><tr><th>Number</th><th>Name</th><th>Link to Character Page</th><tr>';
    var a = list.split(",");
    indexList = a.slice(0); //copy the cgi output to the indexList global variable.
    var aLen = a.length;
    //there are 11 pieces of character info we are using so we have to increment by 12. Also, we are only using three columns for the table.
    for (var i = 0; i < aLen; i+=12) {
	result += "<tr><td>"+a[i] +"</td><td>"+"<div class='charname' data=\'"+ i + "\'>" + a[i+1]+"</div>" + "</td><td>"+ "<a href =" +a[i+2]+ ">Link</a>"+"</td></tr>";
    }
    result += "</table>";

    return result;
}

//function to output information about each character.
//the cgi file gave output for every piece of info for each character so we use the index to access that information.
function lookup(){
  console.log("hello");
  index = $(this).attr("data");
  theWord = $(this).text();
  var  alliance = indexList[+index + 3];
  var identity = indexList[+index + 4];
  var eyes = indexList[+index+5];
  var hair = indexList[+index+6];
  var gender = indexList[+index+7];
  var alive = indexList[+index+8];
  var appearance = indexList[+index+9];
  var date = indexList[+index+10];
  var year = indexList[+index+11];
  alert("Name: " + theWord + "\nAlliance: " + alliance + "\nIdentity: " + identity + "\nEye Color: " + eyes + "\nHair: " + hair + "\nGender: " + gender + "\nAlive or Dead: " + alive + "\nNumber of Appearances in the Marvel Universe: " + appearance + "\nDate of First Appearance: " + date + "\nYear of First Appearance: " + year);

}

function processResults(results) {
    $('#searchresults').empty();
    $('#searchresults').append(nameTable(results));
    $(".charname").click(lookup);
}

function clearResults() {
    $('#searchresults').empty();
}

function getMatches(){
    console.log("getMatches!");
    var searchStr=$('#search').val();
    console.log(searchStr+":"+searchType);
    if (searchStr.length < 2) return;
    $('#searchresults').empty();
    $.ajax({
	url: '/cgi-bin/clark1_marvelSearch.cgi?name='+searchStr+'&type_select='+searchType,
	type: "get",
	dataType: 'text',
	success: processResults,
	error: function(){alert("Error: Something went wrong");}
    });
  console.log("Matches Done");
}
