const char web_index[] PROGMEM = R"=====(
<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>Matrix</title>
  <meta name="description" content="Matrix">
  <meta name="author" content="Tauno Erik">
  <style>
html { font-size: 62.5%; box-sizing: border-box;}

*, *::before, *::after {
  margin: 0;
  padding: 0;
  box-sizing: inherit;
}

.calculator {
  border: 1px solid #ccc;
  width: 100%;
  background-color: #ddd;
}

button {
  height: 80px;
  background-color: #fff;
  border-radius: 3px;
  border: 1px solid #c4c4c4;
  font-size: 3rem;
  color: #333;
}

button:hover { background-color: #ABFF00;}
button:active {border:0;}

.calculator-keys {
  display: grid;
  grid-template-columns: repeat(8, 1fr);
  grid-gap: 2px;
  padding: 2px;
}

.on {
  background-color: #ABFF00;
  box-shadow: rgba(0, 0, 0, 0.2) 0 -1px 7px 1px, inset #304701 0 -1px 9px, #89FF00 0 2px 12px;
}
  </style>
</head>
<body>
<div class="calculator">
    <div class="calculator-keys">
      <button id="11" onclick="sendData(11)">11</button>
      <button id="12" onclick="sendData(12)">12</button>
      <button id="13" onclick="sendData(13)">13</button>
      <button id="14" onclick="sendData(14)">14</button>
      <button id="15" onclick="sendData(15)">15</button>
      <button id="16" onclick="sendData(16)">16</button>
      <button id="17" onclick="sendData(17)">17</button>
      <button id="18" onclick="sendData(18)">18</button>

      <button id="21" onclick="sendData(21)">21</button>
      <button id="22" onclick="sendData(22)">22</button>
      <button id="23" onclick="sendData(23)">23</button>
      <button id="24" onclick="sendData(24)">24</button>
      <button id="25" onclick="sendData(25)">25</button>
      <button id="26" onclick="sendData(26)">26</button>
      <button id="27" onclick="sendData(27)">27</button>
      <button id="28" onclick="sendData(28)">28</button>

      <button id="31" onclick="sendData(31)">31</button>
      <button id="32" onclick="sendData(32)">32</button>
      <button id="33" onclick="sendData(33)">33</button>
      <button id="34" onclick="sendData(34)">34</button>
      <button id="35" onclick="sendData(35)">35</button>
      <button id="36" onclick="sendData(36)">36</button>
      <button id="37" onclick="sendData(37)">37</button>
      <button id="38" onclick="sendData(38)">38</button>
  
      <button id="41" onclick="sendData(41)">41</button>
      <button id="42" onclick="sendData(42)">42</button>
      <button id="43" onclick="sendData(43)">43</button>
      <button id="44" onclick="sendData(44)">44</button>
      <button id="45" onclick="sendData(45)">45</button>
      <button id="46" onclick="sendData(46)">46</button>
      <button id="47" onclick="sendData(47)">47</button>
      <button id="48" onclick="sendData(48)">48</button>
  
      <button id="51" onclick="sendData(51)">51</button>
      <button id="52" onclick="sendData(52)">52</button>
      <button id="53" onclick="sendData(53)">53</button>
      <button id="54" onclick="sendData(54)">54</button>
      <button id="55" onclick="sendData(55)">55</button>
      <button id="56" onclick="sendData(56)">56</button>
      <button id="57" onclick="sendData(57)">57</button>
      <button id="58" onclick="sendData(58)">58</button>
      
      <button id="61" onclick="sendData(61)">61</button>
      <button id="62" onclick="sendData(62)">62</button>
      <button id="63" onclick="sendData(63)">63</button>
      <button id="64" onclick="sendData(64)">64</button>
      <button id="65" onclick="sendData(65)">65</button>
      <button id="66" onclick="sendData(66)">66</button>
      <button id="67" onclick="sendData(67)">67</button>
      <button id="68" onclick="sendData(68)">68</button>
      
      <button id="71" onclick="sendData(71)">71</button>
      <button id="72" onclick="sendData(72)">72</button>
      <button id="73" onclick="sendData(73)">73</button>
      <button id="74" onclick="sendData(74)">74</button>
      <button id="75" onclick="sendData(75)">75</button>
      <button id="76" onclick="sendData(76)">76</button>
      <button id="77" onclick="sendData(77)">77</button>
      <button id="78" onclick="sendData(78)">78</button>
      
      <button id="81" onclick="sendData(81)">81</button>
      <button id="82" onclick="sendData(82)">82</button>
      <button id="83" onclick="sendData(83)">83</button>
      <button id="84" onclick="sendData(84)">84</button>
      <button id="85" onclick="sendData(85)">85</button>
      <button id="86" onclick="sendData(86)">86</button>
      <button id="87" onclick="sendData(87)">87</button>
      <button id="88" onclick="sendData(88)">88</button>
    </div>
  </div>
<script>
function sendData(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "?m="+led, true);
  xhttp.send();
  var element = document.getElementById(led);
  element.classList.toggle("on");
}
</script>
</body>
</html>
)=====";