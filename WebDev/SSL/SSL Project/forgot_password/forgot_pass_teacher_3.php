<?php
	session_start();
	?>
<html>
	<head>
		  <link rel='stylesheet' href='../Design_Components/bootstrap.min.css'>
		<style type="text/css">
			@keyframes AnimationName {
    0% {
        background-position: 0% 50%
    }
    50% {
        background-position: 100% 50%
    }
    100% {
        background-position: 0% 50%
    }
}
			body{
				background: linear-gradient(270deg, #4285f4, #7542f4, #eb42f4);
    background-size: 400% 400%;
    -webkit-animation: AnimationName 4s ease infinite;
    -moz-animation: AnimationName 4s ease infinite;
    animation: AnimationName 4s ease infinite;
				height: 100vh;
			}
			.height-100 {
			    height: 100vh;
			}

			.card {
			    width: 400px;
			    border: none;
			    height: 300px;
			    box-shadow: 0px 5px 20px 0px #d2dae3;
			    z-index: 1;
			    display: flex;
			    justify-content: center;
			    align-items: center
			}

			.card h6 {
			    color: red;
			    font-size: 20px
			}

			.inputs input {
			    width: 40px;
			    height: 40px
			}

			input[type=number]::-webkit-inner-spin-button,
			input[type=number]::-webkit-outer-spin-button {
			    -webkit-appearance: none;
			    -moz-appearance: none;
			    appearance: none;
			    margin: 0
			}

			.card-2 {
			    background:rgba(255, 255, 255, 0.3);
			    padding: 10px;
			    width: 350px;
			    height: 100px;
			    bottom: -50px;
			    left: 20px;
			    position: absolute;
			    border-radius: 5px
			}

			.card-2 .content {
			    margin-top: 50px
			}

			.card-2 .content a {
			    color: red
			}

			.form-control:focus {
			    box-shadow: none;
			    border: 2px solid red
			}

			.validate {
			    border-radius: 20px;
			    height: 40px;
			    background-color: red;
			    border: 1px solid red;
			    width: 140px
			}

		</style>
	</head>
	<body translate="no" >
		<form action="forgot_pass_teacher_4.php" method="POST" onsubmit="return validateForm()">

		 <div class="container height-100 d-flex justify-content-center align-items-center">
		    <div class="position-relative">
		        <div class="card p-2 text-center"><input type="number" id ="otp" name="otp" style="display: none;">
		            <h6>Please enter the one time password <br> to verify your account</h6>
		            <div> <span>A code has been sent to</span> <small>gmail Id</small> </div>
		            <div id="otp" class="inputs d-flex flex-row justify-content-center mt-2"> 
		            	<input class="m-2 text-center form-control rounded" type="number" id="first" maxlength="1" required/>
		            	<input class="m-2 text-center form-control rounded" type="text" id="second" maxlength="1" required/>
		            	<input class="m-2 text-center form-control rounded" type="text" id="third" maxlength="1" required/> 
		            	<input class="m-2 text-center form-control rounded" type="text" id="fourth" maxlength="1" required/>
		            	<input class="m-2 text-center form-control rounded" type="text" id="fifth" maxlength="1" required/> 
						<input class="m-2 text-center form-control rounded" type="text" id="sixth" maxlength="1" required/>
						<input class="m-2 text-center form-control rounded" type="text" id="seventh" maxlength="1" required/>
					</div>
		        	<div class="mt-4"> <input class="btn btn-danger px-4 validate" type="submit" value="Validate"/></div>
		        </div>
		    </div>
		</div>
		
	</form>
  <script src='../Design_Components/bootstrap.min.js'></script>
      <script id="rendered-js" >
      	 function validateForm(){
		   document.getElementById("otp").value=document.getElementById("first").value+document.getElementById("second").value+document.getElementById("third").value+document.getElementById("fourth").value+document.getElementById("fifth").value+document.getElementById("sixth").value+document.getElementById("seventh").value;
		   document.getElementById("otp").innnerHTML=document.getElementById("otp").value;
		   if(document.getElementById("otp").innnerHTML.length<7)
		   {
		   	alert("otp contains only digits");
		   	return false;
		   }
		   return true;
		  }
		document.addEventListener("DOMContentLoaded", function (event) {
		 	function OTPInput() {
			    const inputs = document.querySelectorAll('#otp > *[id]');
			    for (let i = 0; i < inputs.length; i++) {
			    	inputs[i].addEventListener('keydown', function (event) 
			    	{
			    		if (event.key === "Backspace") {
			    			inputs[i].value = '';
			    			if (i !== 0) 
			    				inputs[i - 1].focus();
			    		} else {
			    			if (i === inputs.length - 1 && inputs[i].value !== '') {
			    				return true;
			    			} else if (event.keyCode > 47 && event.keyCode < 58) {
			    				inputs[i].value = event.key;
			    				if (i !== inputs.length - 1) 
			    					inputs[i + 1].focus();event.preventDefault();
			    			} else if (event.keyCode > 64 && event.keyCode < 91) {
			    				inputs[i].value = String.fromCharCode(event.keyCode);
			    				if (i !== inputs.length - 1) 
			    					inputs[i + 1].focus();event.preventDefault();
			    			}
			    		}
			    	});
			    }
			}
			OTPInput();
		});
    </script>

	<!--<body>
		<div class="container height-100 d-flex justify-content-center align-items-center">
			<form action="forgot_pass_stu_4.php" method="POST">
				<div class="container">
				<h2>OTP has been sent to the Regestred<br></h2>
				<h1>Enter 7 digit OTP</h1>
				<div class="userInput">
					<input type="text" id='ist' maxlength="1" onkeyup="clickEvent(this,'sec')" required>
					<input type="text" id="sec" maxlength="1" onkeyup="clickEvent(this,'third')" required>
					<input type="text" id="third" maxlength="1" onkeyup="clickEvent(this,'fourth')" required>
					<input type="text" id="fourth" maxlength="1" onkeyup="clickEvent(this,'fifth')" required>
					<input type="text" id="fifth" maxlength="1" onkeyup="clickEvent(this,'sixth')" required>
					<input type="text" id="sixth" maxlength="1" onkeyup="clickEvent(this,'seventh')" required>
					<input type="text" id="seventh" maxlength="1" required>
				</div>
				<div id="otp" class="inputs d-flex flex-row justify-content-center mt-2"> 
					<input class="m-2 text-center form-control rounded" type="text" id="first" maxlength="1" /> 
					<input class="m-2 text-center form-control rounded" type="text" id="second" maxlength="1" /> 
					<input class="m-2 text-center form-control rounded" type="text" id="third" maxlength="1" /> 
					<input class="m-2 text-center form-control rounded" type="text" id="fourth" maxlength="1" /> 
					<input class="m-2 text-center form-control rounded" type="text" id="fifth" maxlength="1" /> 
					<input class="m-2 text-center form-control rounded" type="text" id="sixth" maxlength="1" /> 
				</div>
           
				<button>CONFIRM</button>
				<input type="number" name="otp" style="display: none;">
				<input type="submit" value="Submit">
				</div>
			</form>
		</div>
		<script src='../Design_Components/bootstrap.min.js'></script>
      <script id="rendered-js" >
			document.addEventListener("DOMContentLoaded", function (event) {

			  function OTPInput() {
			    const inputs = document.querySelectorAll('#otp > *[id]');
			    for (let i = 0; i < inputs.length; i++) {if (window.CP.shouldStopExecution(0)) break;inputs[i].addEventListener('keydown', function (event) {if (event.key === "Backspace") {inputs[i].value = '';if (i !== 0) inputs[i - 1].focus();} else {if (i === inputs.length - 1 && inputs[i].value !== '') {return true;} else if (event.keyCode > 47 && event.keyCode < 58) {inputs[i].value = event.key;if (i !== inputs.length - 1) inputs[i + 1].focus();event.preventDefault();} else if (event.keyCode > 64 && event.keyCode < 91) {inputs[i].value = String.fromCharCode(event.keyCode);if (i !== inputs.length - 1) inputs[i + 1].focus();event.preventDefault();}}});}window.CP.exitedLoop(0);}OTPInput();});

			function clickEvent(first, last) {
			  if (first.value.length) {
			    document.getElementById(last).focus();
			  }
			}
	    </script>-->
	</body>
</html>