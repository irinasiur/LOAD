Action()
{
	lr_start_transaction("UC02_Поиск билета без покупки");
	lr_start_transaction("welcome");


/*Correlation comment - Do not change!  Original value='137547.428432564HAHfAQfpiftctfApfHfV' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_url("webtours", 
		"URL=http://{HOST_PORT}/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);


	lr_end_transaction("welcome",LR_AUTO);



	web_add_header("Origin", 
		"http://{HOST_PORT}");


	lr_think_time(5);
	
		lr_start_transaction("login");

	web_reg_find("Search=All",
		"Text=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action=http://{HOST_PORT}/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{HOST_PORT}/cgi-bin/nav.pl?in=home",
		"Snapshot=t7.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={usernamelogin}", ENDITEM,
		"Name=password", "Value={userpassword}", ENDITEM,
		"Name=login.x", "Value=23", ENDITEM,
		"Name=login.y", "Value=7", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);
	lr_end_transaction("login",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("ticket_search1");
	web_reg_find("Search=All",
		"Text= user has already logged on",
		LAST);

	web_url("welcome.pl", 
		"URL=http://{HOST_PORT}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
      	lr_end_transaction("ticket_search1",LR_AUTO);


	lr_think_time(5);

	lr_start_transaction("ticket_search2");

	web_add_auto_header("Origin", 
		"http://{HOST_PORT}");


	web_submit_data("reservations.pl", 
		"Action=http://{HOST_PORT}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=66", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("ticket_search2",LR_AUTO);

	/*lr_start_transaction("choose_time");

	web_reg_find("Search=All",
		"Text= value=\"{usernamelogin}\"",
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action=http://{HOST_PORT}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/reservations.pl", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outFlightVal_1}", ENDITEM, //010;386;10/24/2023 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=30", ENDITEM, 
		"Name=reserveFlights.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("choose_time",LR_AUTO);


	lr_think_time(5);

	lr_start_transaction("payment");


	web_add_header("Origin", 
		"http://{HOST_PORT}");


	lr_think_time(5);

	web_reg_find("Search=All",
		"Text=Thank you",
		LAST);

	web_submit_data("reservations.pl_3",
		"Action=http://{HOST_PORT}/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{HOST_PORT}/cgi-bin/reservations.pl",
		"Snapshot=t15.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={firstName}", ENDITEM,
		"Name=lastName", "Value={lastName}", ENDITEM,
		"Name=address1", "Value={address1}", ENDITEM,
		"Name=address2", "Value={address2}", ENDITEM,
		"Name=pass1", "Value={pass1}", ENDITEM,
		"Name=creditCard", "Value={creditCard}", ENDITEM,
		"Name=expDate", "Value={expDate}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outFlightVal_1}", ENDITEM, //010;386;10/24/2023
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=30", ENDITEM,
		"Name=buyFlights.y", "Value=9", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);

	lr_end_transaction("payment",LR_AUTO); */

	lr_think_time(5);
	
	lr_start_transaction("signoff");



	web_reg_find("Search=All",
		"Text=A Session ID has been created",
		LAST);

	web_url("welcome.pl_2", 
		"URL=http://{HOST_PORT}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("signoff",LR_AUTO);
	lr_end_transaction("UC02_Поиск билета без покупки",LR_AUTO);

	return 0;
}