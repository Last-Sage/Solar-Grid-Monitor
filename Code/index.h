const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style>
html{
background: #3F6634;
}
body{
    max-width: 100%;
    height: auto;
    background: #4FB477;
    padding: 30px;
    color: #FFF;
    margin: 0% 5% 5% 5%;
    border: 0px;
    border-radius: 0px 0px 25px 25px;
    box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75); 
}
.card{
    color: #DCFFFD;
    font-family: sans-serif;
    text-align: center;
}
.tab {
    overflow: hidden;
    display: flex;
    justify-content: space-around;
    align-items: center;
    border: 0px;
    border-radius: 0px 0px 25px 25px;
    background-color: #DCFFFD;
    box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
/* Style the buttons that are used to open the tab content */
.tab button {
background-color: inherit;
width: 100%;
color: #345511;
font-size: 100%;
border: none;
font-weight: bold;
outline: none;
cursor: pointer;
padding: 14px 16px;
transition: 0.3s;
}
/* Change background color of buttons on hover */
.tab button:hover {
background-color: #52FFEE;
}
/* Create an active/current tablink class */
.tab button.active {
background-color: #52FFEE;
}
/* Style the tab content */
.tabcontent {
display: none;
background: #DCFFFD;
font-family: sans-serif;
color: #345511;
padding: 6px 12px;
border: 0px;
border-radius: 25px 25px 0px 0px;
box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
</style>
<body>
<div class="card">
<br>
<br>
<br>
<br>
<br>
<br>
<h1>KSEB - SOLAR MONITOR</h1><br>
<br>
<br>
</div>
<!-- Tab content -->
<div id="Pulse" class="tabcontent">
<br>
<h2>KSEB pulse : <span id="ksebPulse">0</span></h2><br>
<h2>Solar pulse : <span id="solarPulse">0</span></h2>
<br>
</div>
<div id="KWh" class="tabcontent">
<br>
<h2>KSEB : <span id="ksebUnit">0</span> KWh</h2><br>
<h2>Solar : <span id="solarUnit">0</span> KWh</h2>
<br>
</div>
<div id="Wh" class="tabcontent">
<br>
<h2>KSEB : <span id="ksebwh">0</span> Wh</h2><br>
<h2>Solar : <span id="solarwh">0</span> Wh</h2>
<br>
</div>
<div id="Price" class="tabcontent">
<br>
<h2>KSEB : <span id="ksebprice">0</span> Rs</h2><br>
<h2>Solar : <span id="solarprice">0</span> Rs</h2><br>
<h2>Net : <span id="netprice">0</span> Rs</h2><br>
<br>
</div>
<!-- Tab links -->
<div class="tab">
<button class="tablinks" onclick="openTab(event, ’Pulse’)">Pulse</button>
<button class="tablinks" onclick="openTab(event, ’KWh’)">KWh</button>
<button class="tablinks" onclick="openTab(event, ’Wh’)">Wh</button>
<button class="tablinks" onclick="openTab(event, ’Price’)">Price</button>
</div>
<script>
function openTab(event, tabName) {
// Declare all variables
var i, tabcontent, tablinks;
// Get all elements with class="tabcontent" and hide them
tabcontent = document.getElementsByClassName("tabcontent");
for (i = 0; i < tabcontent.length; i++) {
tabcontent[i].style.display = "none";
}
// Get all elements with class="tablinks" and remove the class "active"
tablinks = document.getElementsByClassName("tablinks");
for (i = 0; i < tablinks.length; i++) {
tablinks[i].className = tablinks[i].className.replace(" active", "");
}
// Show the current tab, and add an "active" class to the button that opened the tab
document.getElementById(tabName).style.display = "block";
evt.currentTarget.className += " active";
}
setInterval(function() {
// Call a function repetatively with 1 Second interval
getData();
}, 1000); //2000mSeconds update rate
function getData() {
var xhttp = new XMLHttpRequest();
xhttp.onreadystatechange = function() {
if (this.readyState == 4 && this.status == 200) {
var recived_data = this.responseText.split(’|’);
var ksebPulse = recived_data[0];
var solarPulse = recived_data[1];
console.log(recived_data);
document.getElementById("ksebPulse").innerHTML = ksebPulse;
document.getElementById("solarPulse").innerHTML = solarPulse;
var ksebUnit = (parseFloat(ksebPulse)*0.0003125)
var solarUnit = (parseFloat(solarPulse)*0.0003125)
var ksebwh = (parseFloat(ksebPulse)*0.3125)
var solarwh = (parseFloat(solarPulse)*0.3125)
document.getElementById("ksebUnit").innerHTML = ksebUnit;
document.getElementById("solarUnit").innerHTML = solarUnit;
document.getElementById("ksebwh").innerHTML = ksebwh;
document.getElementById("solarwh").innerHTML = solarwh;
var ksebprice = 0;
var solarprice = 0;
var netprice= ksebprice+solarprice;
if(ksebUnit<=50)
{
ksebprice=ksebUnit*3.15;
}
else if(ksebUnit<=100)
{
ksebprice=157.5+(ksebUnit-50)*3.70;
}
else if(ksebUnit<=150)
{
ksebprice=342.5+(ksebUnit-100)*4.80;
}
else if(ksebUnit<=200)
{
ksebprice=582.5+(ksebUnit-150)*6.40;
}
else if(ksebUnit<=250)
{
ksebprice=902+(ksebUnit-200)*7.60;
}
else if(ksebUnit<=300)
{
ksebprice=ksebUnit*5.80;
}
else if(ksebUnit<=350)
{
ksebprice=ksebUnit*6.60;
}
else if(ksebUnit<=400)
{
ksebprice=ksebUnit*6.90;
}
else if(ksebUnit<=500)
{
ksebprice=ksebUnit*7.10;
}
else if(ksebUnit>500)
{
ksebprice=ksebUnit*7.90;
}
if(solarUnit<=50)
{
solarprice=solarUnit*3.15;
}
else if(solarUnit<=100)
{
solarprice=157.5+(solarUnit-50)*3.70;
}
else if(solarUnit<=150)
{
solarprice=342.5+(solarUnit-100)*4.80;
}
else if(solarUnit<=200)
{
solarprice=582.5+(solarUnit-150)*6.40;
}
else if(solarUnit<=250)
{
solarprice=902+(solarUnit-200)*7.60;
}
else if(solarUnit<=300)
{
solarprice=solarUnit*5.80;
}
else if(solarUnit<=350)
{
solarprice=solarUnit*6.60;
}
else if(solarUnit<=400)
{
solarprice=solarUnit*6.90;
}
else if(solarUnit<=500)
{
solarprice=solarUnit*7.10;
}
else if(solarUnit>500)
{
solarprice=solarUnit*7.90;
}
netprice=ksebprice-solarprice;
document.getElementById("solarprice").innerHTML = solarprice;
document.getElementById("ksebprice").innerHTML = ksebprice;
document.getElementById("netprice").innerHTML = netprice;
}
};
xhttp.open("GET", "readADC", true);
xhttp.send();
}
</script>
</html>
)=====";