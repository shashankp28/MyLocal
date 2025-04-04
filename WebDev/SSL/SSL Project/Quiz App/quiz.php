<?php 
session_start(); 
date_default_timezone_set('Asia/Kolkata');
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "trupendb";
$conn = new mysqli($servername, $username, $password, $dbname);
$sql = "SELECT time, time_limit FROM quiz WHERE name = '".$_POST["quiz_name"]."' AND subject = '".$_POST["quiz_subject"]."'";
$result = $conn->query($sql);
while($row = $result->fetch_assoc())
{
	$to_time = strtotime(implode(" ", explode("T", $row["time"])));
	$time_limit = $row["time_limit"];
	$from_time = strtotime(date('Y-m-d H:i:s'));
	$t = $from_time - $to_time;
}
if($t<0)
{
	header("location:javascript://history.go(-1)");
	exit();
}
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
$_SESSION["quiz_name"] = $_POST["quiz_name"];
$_SESSION["quiz_subject"] = $_POST["quiz_subject"];
$qryst="select * from ".$_SESSION["quiz_subject"].'_'.$_SESSION["quiz_name"];
     $result = $conn->query($qryst);
?>
<html>
<head>
<title><?php echo "Quiz : ".$_SESSION["quiz_name"]; ?></title>
<link rel="stylesheet" href="style.css?v=<?php echo time(); ?>">
<link rel = "icon" href ="../Image_Components/truPen Better Logo.png"  type = "image/x-icon">
<style>
  * {box-sizing: border-box}
      body {
        font-family: Verdana, sans-serif; margin:0;
        background: #f4ffff;
      }
      .mySlides {
        display: none;
        height: 500px;
      }
      .main-container {
        display:flex;
        /*flex-flow: row wrap;*/
        padding: 20px;
        margin: 0px;
        margin-left: 100px;
        height:80%;
        max-width:1300px;
      }
      /* Slideshow container */
      .slideshow-container {
        float: left;
        max-width: 700px;
        min-width: 600px;
        max-height: 500px;
        min-height: 400px;
      }
      .slideshow-container form {
        max-width: 700px;
        min-width: 600px;
        max-height: 500px;
        min-height: 400px;
      }
      .slideshow-container .navstp{
        display: inline-block;
        padding: 3px;
        background-color: #f1f1f1;
        width:100%;
        height:63px;
      }
      /* Next & previous buttons */
      .prev, .next {
        cursor: pointer;
        background-color: rgba(0,0,0,0.1);
        margin-left: 5px;
        margin-right: 5px;
        width: auto;
        padding: 16px;
        color: white;
        font-weight: bold;
        font-size: 18px;
        transition: 0.6s ease;
        border-radius: 10%;
        user-select: none;
      }
      .first{
        cursor: pointer;
        float: left;
        background-color: rgba(100,0,0,0.5);
        width: auto;
        padding: 16px;
        color: white;
        font-weight: bold;
        font-size: 18px;
        transition: 0.6s ease;
        border-radius: 10%;
        user-select: none;
      }
      .last {
        cursor: pointer;
        float: right;
        background-color: rgba(0,100,0,0.5);
        width: auto;
        padding: 16px;
        color: white;
        font-weight: bold;
        font-size: 18px;
        transition: 0.6s ease;
        border-radius: 10%;
        user-select: none;
      }
      /* Position the "next button" to the right */
      .next {
        float: right;
      }
      .prev {
        float: left;
      }

      /* On hover, add a black background color with a little bit see-through */
      .prev:hover, .next:hover {
        background-color: rgba(0,0,0,0.8);
        border: 2px solid rgba(200,250,250,0.8);
      }
      .first:hover{
        background-color: rgba(100,0,0,0.8);
        border: 2px solid rgba(200,150,200,0.8);
      }
      .last:hover {
        background-color: rgba(0,100,0,0.8);
        border: 2px solid rgba(200,150,200,0.8);
      }

      /* Caption text */
      .text {
        color: #f2f2f2;
        background-color: rgba(0,0,0,0.6);
        font-size: 15px;
        padding: 8px 12px;
        position: relative;
        bottom: -70px;
        width: 100%;
        text-align: center;
      }

      /* Number text (1/3 etc) */
      .numbertext {
        color: #f2f2f2;
        background-color: rgba(0,0,0,0.4);
        font-size: 12px;
        padding: 8px 12px;
        text-align: center;
        margin-left:85%;
        top: 0;
      }

      /* The dots/bullets/indicators */
      .dot {
        cursor: pointer;
        height: 15px;
        width: 15px;
        margin: 0 2px;
        background-color: #bbb;
        border-radius: 50%;
        display: inline-block;
        transition: background-color 0.6s ease;
      }

      .active, .dot:hover {
        background-color: #717171;
      }

      /* Fading animation */
      .fade {
        -webkit-animation-name: fade;
        -webkit-animation-duration: 1.5s;
        animation-name: fade;
        animation-duration: 1.5s;
      }

      @-webkit-keyframes fade {
        from {opacity: .4} 
        to {opacity: 1}
      }

      @keyframes fade {
        from {opacity: .4} 
        to {opacity: 1}
      }

      /* On smaller screens, decrease text size */
      @media only screen and (max-width: 300px) {
        .prev, .next,.text {font-size: 11px}
      }

      .quiz-container{
        background-color: #fff;
        border-radius: 10px;
        box-shadow: 0 0 10px 2px rgba(100, 100, 100, 0.1);
        width: 100%;
        height: 100%;
        overflow: hidden;
      }
      .quiz-header{
        padding: 4rem;
      }
      h2{
        padding: 1rem;
        margin: 0;
      }

      ul{
        list-style-type: none;
        padding: 0;
      }
      ul li{
        font-size: 1.2rem;
        margin: 1.3rem 1rem;
      }
      ul li label{
        cursor: pointer;
      }

      .container {
          position: relative;
          padding: 50px;
          width: 260px;
          min-height: 30px;
          display: flex;
          justify-content: center;
          align-items: center;
          background: rgba(255, 255, 255, 0.2);
          backdrop-filter: blur(5px);
          border-radius: 10px;
          box-shadow: 0 25px 45px rgba(0, 0, 0, 0.2);
      }

      .openbtn1 {
        font-size: 20px;
        cursor: pointer;
        background-color: #111;
        color: white;
        padding: 10px 15px;
        border: none;
      }

      .openbtn1:hover {
        background-color:#444;
      }

      .circlestyle{
        border:none;
        background-color:cyan;
        box-shadow: 10px;
        border-radius: 50%;
        padding:5px;
      }
      .exitit{
        background-color: #455d80;
          border: none;
          color: white;
          padding: 10px 20px;
          text-align: center;
          text-decoration: none;
          display: inline-block;
          font-size: 16px;
          margin: 4px 2px;
          cursor: pointer;
      }
      .exitit:hover {
          background-color: #2a384d;
          border: none;
          color: white;
          padding: 10px 20px;
          text-align: center;
          text-decoration: none;
          display: inline-block;
          font-size: 16px;
          margin: 4px 2px;
          cursor: pointer;
      }


      .navboxd {
			  display: block;
        float: right;
			  height: 90%;
			  width: 275px;
			  align-content: center;
			  background-color: rgba(235,235,235,0.13);
			  border-radius: 10px;
			  backdrop-filter: blur(10px);
			  border: 2px solid rgba(255,255,255,0.1);
			  box-shadow: 0 0 40px rgba(8,7,16,0.6);
			}
			.flexbox {
			  display: flex;
			  padding-left: 5px;
			  padding-right: 5px;
        margin: 5px;
			  flex-flow: row wrap;
			  width: 260px; /* 4 items * item width(100+5+5) = 440 */
			  background-color: rgba(235,235,235,0.13);
			  border-radius: 10px;
			  backdrop-filter: blur(10px);
			  border: 2px solid rgba(255,255,255,0.1);
			  box-shadow: 0 0 40px rgba(8,7,16,0.6);
			}

			.flexbox .flex-item {
			  padding: 5px;
			  margin: 5px;
			  width: 45px;
        cursor: pointer;
			  height: 45px;
			  align-content: center;
			  vertical-align: center;
			  border-radius: 35% 60%;
			  background-color:  #999999;
			}
      .flexbox .act {
			  /*background-color: #999999;*/
        border-radius: 25%;
        color: #0000ff;
        font-size:22px;
        border-color:#ffffff;
			}
      .flexbox .flex-item .act{
			  display: block;
			  padding: 0 auto;
			  margin: 0 auto;
        height:32px;
			  border-color: black;
        font-size:18px;
        border-radius: 25%;
			  background: #555;
			  box-shadow: 5px;
			  text-align: center;
        justify-content: center;
			}
      .flexbox .lft {
			  display: block;
			  padding: 5px;
			  margin: 5px;
			  border-color:#ff00af;
			  background-color: #da0000;
			  box-shadow: 5px;
			  text-align: center;
			}

      .flexbox .atm {
			  display: block;
			  padding: 5px;
			  margin: 5px;
			  border-color:#00ff00;
			  background-color: #00da00;
			  box-shadow: 5px;
			  text-align: center;
			}
			.flexbox .flex-item .con {
			  display: block;
			  padding: 5px;
			  margin: 5px;
        height: 25px;
			  border-radius: 50%;
			  border-color: black;
			  background-color: #fff;
			  box-shadow: 5px;
			  text-align: center;
			}
			.flexbox .flex-item-rev .con {
			  display: block;
			  padding: 5px;
			  margin: 5px;
			  border-radius: 50%;
			  border-color: black;
			  background-color: #fff;
			  box-shadow: 5px;
			  text-align: center;
			}
			.flexbox .flex-item-attempt .con {
			  display: block;
			  padding: 5px;
			  margin: 5px;
			  border-radius: 50%;
			  border-color: black;
			  background-color: #fff;
			  box-shadow: 5px;
			  text-align: center;
			}
			.flexbox .flex-item-leftb .con {
			  display: block;
			  padding: 5px;
			  margin: 5px;
			  border-radius: 50%;
			  border-color: black;
			  background-color: #ff0000;
			  box-shadow: 5px;
			  text-align: center;
			}
      .flexbox .flex-item-rev {
			  padding: 5px;
			  margin: 5px;
			  width: 45px;
			  height: 45px;
			  align-content: center;
			  vertical-align: center;
			  border-radius: 50%;
			  background-color: #aa00aa;
			}
			.flexbox .flex-item-leftb {
			  padding: 5px;
			  margin: 5px;
			  width: 45px;
			  height: 45px;
			  align-content: center;
			  vertical-align: center;
			  border-radius: 50%;
			  background-color: #a00;
			}
			.flexbox .flex-item-attempt {
			  padding: 5px;
			  margin: 5px;
			  width: 45px;
			  height: 35px;
			  align-content: center;
			  vertical-align: center;
			  border-radius: 50%;
			  background-color: #0f0;
			}
      
			.head {
			  padding: 5px;
			  margin: 5px;
			  text-align: center;
			  background-color: rgba(235,235,235,0.13);
			  border-radius: 10px;
			  backdrop-filter: blur(10px);
			  border: 2px solid rgba(255,255,255,0.1);
			  box-shadow: 0 0 40px rgba(8,7,16,0.6);
			}
			.botm{
				  padding: 5px;
			    margin: 5px;
          position: absolute;
          bottom: 0;
          width:96%;
			    text-align: center;
			    background-color: rgba(0,0,255,0.23);
			    border-radius: 10px;
			    backdrop-filter: blur(10px);
			    border: 2px solid rgba(255,255,255,0.1);
			    box-shadow: 0 0 40px rgba(8,7,16,0.6);
          background-color: #03cae4;
			}
			.botm .btn { 
			  border-radius: 5px;
			  border: 4px solid rgba(255,255,255,0.2);
        color: #fff;
        border: none;
        display:inline-flex;
        width: 100%;
        font-size: 1 rem;
        font-family: sans-serif;
        padding: 1rem;
        background-color: rgba(20,25,235,0.13);
    }
    .btn:hover {
      border: 4px solid rgba(255,255,255,0.8);
      background-color: rgba(200,25,25,0.4);
    }

    .btn:focus {
      outline: none;
      background-color: rgba(200,250,235,0.13);
  }
  .timer-container {
			  display: block;
        float: right;
			  width: 275px;
			  align-content: center;
			  background-color: rgba(235,235,235,0);
			  border-radius: 10px;
			  backdrop-filter: blur(10px);
			  border: 1px solid rgba(255,255,255,0);
			  box-shadow: 0 0 40px rgba(8,7,16,0);
  }
  .base-timer {
        position: relative;
        width: 100px;
        height: 100px;
    }
    
    .base-timer__svg {
        transform: scaleX(-1);
    }
    
    .base-timer__circle {
        fill: none;
        stroke: none;
    }
    
    .base-timer__path-elapsed {
        stroke-width: 7px;
        stroke: grey;
    }
    
    .base-timer__path-remaining {
        stroke-width: 7px;
        stroke-linecap: round;
        transform: rotate(90deg);
        transform-origin: center;
        transition: 1s linear all;
        fill-rule: nonzero;
        stroke: currentColor;
    }
    
    .base-timer__path-remaining.green {
        color: rgb(65, 184, 131);
    }
    
    .base-timer__path-remaining.orange {
        color: orange;
    }
    
    .base-timer__path-remaining.red {
        color: red;
    }
    
    .base-timer__label {
        position: absolute;
        width: 100px;
        height: 100px;
        top: 0;
        display: flex;
        align-items: center;
        justify-content: center;
        font-size: 25px;
    }
</style>
</head>
<body style="margin-left:10px;margin-top:8px;margin-bottom:10px">

            <div class="main-container">
              <div class="slideshow-container">
                <form method="post" action="evaluation.php" id="myform">
                          <?php
                            $x=0;
                            if ($result && $result->num_rows > 0) {
                              global $x;
                              for ($x = 0;$row = $result->fetch_assoc(); $x++) {
                                echo '<div class="mySlides fade" id="'.$x.'">
                                        <div class="quiz-container" id="quiz">
                                          <div class="quiz-header">
                                            <div class="numbertext">'.($x+1).' /'.$result->num_rows.'</div>
                                            <h2>'.$row["question"].'</h2>
                                            <ul>
                                              <li><input type="radio" name="answer'.$x.'" id="a" onclick="check_select()" class="answer" value="a_'.$x.'"><label for="a" id="a_text">'.$row["option_a"].'</label></li>
                                              <li><input type="radio" name="answer'.$x.'" id="b" onclick="check_select()" class="answer" value="b_'.$x.'"><label for="b" id="b_text">'.$row["option_b"].'</label></li>
                                              <li><input type="radio" name="answer'.$x.'" id="c" onclick="check_select()" class="answer" value="c_'.$x.'"><label for="c" id="c_text">'.$row["option_c"].'</label></li>
                                              <li><input type="radio" name="answer'.$x.'" id="d" onclick="check_select()" class="answer" value="d_'.$x.'"><label for="d" id="d_text">'.$row["option_d"].'</label></li>
                                            </ul>
                                          </div>
                                        </div>
                                      </div>';
                              }
                            }
                          ?>
                  <button type="submit" id="s">Submit</button>
                  <a class="next" onclick="plusSlides(1)">Next</a>
                </form>
                <br>
                <br>
                <br>
                <div class="navstp">
                  <a  class="prev" onclick="plusSlides(-1)">&#10094;</a>
                  <a class="first" onclick="firstSlide()">&#10094;&#10094;</a>
                  <a class="next" onclick="plusSlides(1)">&#10095;</a>
                  <a class="last" onclick="lastSlide()">&#10095;&#10095;</a>
                </div>
              </div>
                    <?php
                      echo'
                      <div class="timer-container" style="margin-right: 10pt;">
                          <p id="app"></p>
                      </div>
                      <div class="navboxd">
                          <h3 class="head">Quiz Navigation</h3>
                          <hr noshade="2">
                          <div class="flexbox">';
                          //echo"<a style='color:#f1f1f1'>QUESTIONS</a>";
                          for($i=1;$i<=$x;$i++){
                              $i1=$i-1;
                              //echo '<a onclick="currentSlide('.$i1.')">'.$i.'</a>';
                              echo'<div class="flex-item">
                                      <a onclick="currentSlide('.$i1.')">
                                      <h6 class="con">'.$i.'</h6></a>
                                  </div>';
                           }
                        echo '</div>
                        <form action="../loggedin.php">
                                <center><input type="submit" value="Exit Quiz" class="exitit"></center>
                              </form>
                      </div>';
                    ?>
            </div>

            <?php
              $max = max(60*$time_limit-$t, 0);
                echo "
                <script> let TIME_LIMIT =$max;
                  let TL =$t;  
                </script>";
              ?>
<script>
var slideIndex = 1;
showSlides(slideIndex);

function plusSlides(n) {
  showSlides(slideIndex += n);
}

function firstSlide() {
  showSlides(slideIndex =1);
}

function lastSlide() {
  showSlides(slideIndex =-200);
}

function currentSlide(n) {
  showSlides(slideIndex = n+1);
}

function showSlides(n) {
  var i;
  var slides = document.getElementsByClassName("mySlides");
  var dots = document.getElementsByClassName("flex-item");
  if (n > slides.length) {slideIndex = 1}    
  if (n < 1) {slideIndex = slides.length}
  for (i = 0; i < slides.length; i++) {
      slides[i].style.display = "none";  
  }
  check_select();
  for (i = 0; i < dots.length; i++) {
    if(dots[i].className.includes(" act") && !dots[i].className.includes(" lft") && !dots[i].className.includes(" atm")){
      dots[i].className += " lft"; //dots[i].className.replace(" act", "");
    }
      dots[i].className = dots[i].className.replace(" act", "");
  }
  slides[slideIndex-1].style.display = "block";  
  if(dots[slideIndex-1].className.includes(" lft")){
      dots[slideIndex-1].className.replace(" lft", "");
  }
  dots[slideIndex-1].className += " act";
}
function check_select() { 
            let k='input[name= "answer'+String(slideIndex-1)+'"]:checked';
            var checkRadio = document.querySelector(k);
            var dots = document.getElementsByClassName("flex-item");
            if(checkRadio != null) {
              if(dots[slideIndex-1].className.includes(" lft")){
                dots[slideIndex-1].className = dots[slideIndex-1].className.replace(" lft", "");
              }
              if(!dots[slideIndex-1].className.includes(" atm")){
                dots[slideIndex-1].className += " atm";
              }
            }
            else {

            }
            
        }
function toggle() {
                var x = document.getElementById("mySidePanel");
                var y = document.getElementById("rotation");
                if (x.style.width === "250px") {
                    y.classList.add("rotation");
                    closeNav();
                } else {
                    y.classList.add("rotation");
                    openNav();
                }
                setTimeout(() => {
                    y.classList.remove("rotation");
                }, 1050);
            }

            function openNav() {
                document.getElementById("mySidePanel").style.width = "250px";
            }

            function closeNav() {
                document.getElementById("mySidePanel").style.width = "0";
            }
  // code for timer :
    const FULL_DASH_ARRAY = 283;
        const WARNING_THRESHOLD = 30;
        const ALERT_THRESHOLD = 10;

        const COLOR_CODES = {
            info: {
                color: "green"
            },
            warning: {
                color: "orange",
                threshold: WARNING_THRESHOLD
            },
            alert: {
                color: "red",
                threshold: ALERT_THRESHOLD
            }
        };
        //const TIME_LIMIT = 100;
        //TIME_LIMIT = window.sessionStorage.getItem("Time");
        let timePassed = 0;
        let timeLeft = TIME_LIMIT;
        let timerInterval = null;
        let remainingPathColor = COLOR_CODES.info.color;

        document.getElementById("app").innerHTML = `
<div class="base-timer">
  <svg class="base-timer__svg" viewBox="0 0 100 100" xmlns="http://www.w3.org/2000/svg">
    <g class="base-timer__circle">
      <circle class="base-timer__path-elapsed" cx="50" cy="50" r="45"></circle>
      <path
        id="base-timer-path-remaining"
        stroke-dasharray="283"
        stroke-dashoffset="0"
        class="base-timer__path-remaining ${remainingPathColor}"
        d="
          M 50, 50
          m -45, 0
          a 45,45 0 1,0 90,0
          a 45,45 0 1,0 -90,0
        "
      ></path>
    </g>
  </svg>
  <span id="base-timer-label" class="base-timer__label">${formatTime(timeLeft)}</span>
</div>
`;

        startTimer();

        function onTimesUp() {
            clearInterval(timerInterval);
        }

        function startTimer() {
            timerInterval = setInterval(() => {
                timePassed = timePassed += 1;
                timeLeft = TIME_LIMIT - timePassed;
                //window.sessionStorage.setItem("time",timeLeft);
                document.getElementById("base-timer-label").innerHTML = formatTime(
                    timeLeft
                );
                setCircleDasharray();
                setRemainingPathColor(timeLeft);

                if (timeLeft <= 0) {
                    onTimesUp();
                    location.reload();
                    document.getElementById("myform").submit();
                    //window.sessionStorage.setItem("time",0);
                    return ;
                }
            }, 1000);
        }
        function formatTime(time) {
            const minutes = Math.floor(time / 60);
            let seconds = time % 60;

            if (seconds < 10) {
                seconds = `0${seconds}`;
            }

            return `${minutes}:${seconds}`;
        }

        function setRemainingPathColor(timeLeft) {
            const {
                alert,
                warning,
                info
            } = COLOR_CODES;
            if (timeLeft <= alert.threshold) {
                document
                    .getElementById("base-timer-path-remaining")
                    .classList.remove(warning.color);
                document
                    .getElementById("base-timer-path-remaining")
                    .classList.add(alert.color);
            } else if (timeLeft <= warning.threshold) {
                document
                    .getElementById("base-timer-path-remaining")
                    .classList.remove(info.color);
                document
                    .getElementById("base-timer-path-remaining")
                    .classList.add(warning.color);
            }
        }

        function calculateTimeFraction() {
            const rawTimeFraction = timeLeft / TIME_LIMIT;
           // return rawTimeFraction - (1 / TIME_LIMIT) * (1 - rawTimeFraction);
          return rawTimeFraction;
        }

        function setCircleDasharray() {
            //const circleDasharray = `${(calculateTimeFraction() * FULL_DASH_ARRAY).toFixed(0)} 360`;
            const circleDasharray = ((TIME_LIMIT-timeLeft)/TIME_LIMIT*283).toString();;
            document.getElementById("base-timer-path-remaining").setAttribute("stroke-dashoffset", circleDasharray);
        }
</script>
<script type="text/javascript">
function forcesubmit() {
  document.getElementById("myform").submit();
}
</script>
</body>
</html>