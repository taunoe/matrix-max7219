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

button:hover { background-color: #eaeaea;}

.all-clear {
  background-color: #f0595f;
  border-color: #b0353a;
  color: #fff;
}

.all-clear:hover { background-color: #f17377;}

.calculator-keys {
  display: grid;
  grid-template-columns: repeat(8, 1fr);
  grid-gap: 2px;
  padding: 2px;
}
  </style>

</head>

<body>
<form action="/" method="GET">
<div class="calculator">
    <div class="calculator-keys">
      <button type="submit" name="m" value="11">11</button>
      <button type="submit" name="m" value="12">12</button>
      <button type="submit" name="m" value="13">13</button>
      <button type="submit" name="m" value="14">14</button>
      <button type="submit" name="m" value="15">15</button>
      <button type="submit" name="m" value="16">16</button>
      <button type="submit" name="m" value="17">17</button>
      <button type="submit" name="m" value="18">18</button>

      <button type="submit" name="m" value="21">21</button>
      <button type="submit" name="m" value="22">22</button>
      <button type="submit" name="m" value="23">23</button>
      <button type="submit" name="m" value="24">24</button>
      <button type="submit" name="m" value="25">25</button>
      <button type="submit" name="m" value="26">26</button>
      <button type="submit" name="m" value="27">27</button>
      <button type="submit" name="m" value="28">28</button>

      <button type="submit" name="m" value="31">31</button>
      <button type="submit" name="m" value="32">32</button>
      <button type="submit" name="m" value="33">33</button>
      <button type="submit" name="m" value="34">34</button>
      <button type="submit" name="m" value="35">35</button>
      <button type="submit" name="m" value="36">36</button>
      <button type="submit" name="m" value="37">37</button>
      <button type="submit" name="m" value="38">38</button>
  
      <button type="submit" name="m" value="41">41</button>
      <button type="submit" name="m" value="42">42</button>
      <button type="submit" name="m" value="43">43</button>
      <button type="submit" name="m" value="44">44</button>
      <button type="submit" name="m" value="45">45</button>
      <button type="submit" name="m" value="46">46</button>
      <button type="submit" name="m" value="47">47</button>
      <button type="submit" name="m" value="48">48</button>
  
      <button type="submit" name="m" value="51">51</button>
      <button type="submit" name="m" value="52">52</button>
      <button type="submit" name="m" value="53">53</button>
      <button type="submit" name="m" value="54">54</button>
      <button type="submit" name="m" value="55">55</button>
      <button type="submit" name="m" value="56">56</button>
      <button type="submit" name="m" value="57">57</button>
      <button type="submit" name="m" value="58">58</button>
      
      <button type="submit" name="m" value="61">61</button>
      <button type="submit" name="m" value="62">62</button>
      <button type="submit" name="m" value="63">63</button>
      <button type="submit" name="m" value="64">64</button>
      <button type="submit" name="m" value="65">65</button>
      <button type="submit" name="m" value="66">66</button>
      <button type="submit" name="m" value="67">67</button>
      <button type="submit" name="m" value="68">68</button>
      
      <button type="submit" name="m" value="71">71</button>
      <button type="submit" name="m" value="72">72</button>
      <button type="submit" name="m" value="73">73</button>
      <button type="submit" name="m" value="74">74</button>
      <button type="submit" name="m" value="75">75</button>
      <button type="submit" name="m" value="76">76</button>
      <button type="submit" name="m" value="77">77</button>
      <button type="submit" name="m" value="78">78</button>
      
      <button type="submit" name="m" value="81">81</button>
      <button type="submit" name="m" value="82">82</button>
      <button type="submit" name="m" value="83">83</button>
      <button type="submit" name="m" value="84">84</button>
      <button type="submit" name="m" value="85">85</button>
      <button type="submit" name="m" value="86">86</button>
      <button type="submit" name="m" value="87">87</button>
      <button type="submit" name="m" value="88">88</button>
    </div>
  </div>
</form>
</body>
</html>
)=====";