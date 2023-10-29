Action()
{
	int arrSize;
	int i;
		lr_start_transaction("UC05_Cancel_Booking");
	lr_start_transaction("welcome");

	web_custom_request("webtours", 
		"URL=http://{HOST_PORT}/webtours/", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("header.html", 
		"URL=http://{HOST_PORT}/webtours/header.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/webtours/", 
		"Snapshot=t2.inf", 
		"Mode=HTTP", 
		LAST);


	web_custom_request("welcome.pl", 
		"URL=http://{HOST_PORT}/cgi-bin/welcome.pl?signOff=true", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/webtours/", 
		"Snapshot=t4.inf", 
		"Mode=HTTP", 
		LAST);


	web_custom_request("home.html", 
		"URL=http://{HOST_PORT}/WebTours/home.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t6.inf", 
		"Mode=HTTP", 
		LAST);

	
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

	web_custom_request("nav.pl", 
		"URL=http://{HOST_PORT}/cgi-bin/nav.pl?in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t8.inf", 
		"Mode=HTTP", 
		LAST);


	lr_end_transaction("welcome",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("login");
	
	web_add_header("Origin", 
		"http://{HOST_PORT}");

		
	web_custom_request("login.pl", 
		"URL=http://{HOST_PORT}/cgi-bin/login.pl", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t31.inf", 
		"Mode=HTTP", 
		"Body=userSession={userSession}&username={usernamelogin}&password={userpassword}&login.x=49&login.y=7&JSFormSubmit=off", 
		LAST);

	web_custom_request("login.pl_2", 
		"URL=http://{HOST_PORT}/cgi-bin/login.pl?intro=true", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/login.pl", 
		"Snapshot=t32.inf", 
		"Mode=HTTP", 
		LAST);

	
	web_custom_request("nav.pl_2", 
		"URL=http://{HOST_PORT}/cgi-bin/nav.pl?page=menu&in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/login.pl", 
		"Snapshot=t33.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("login", LR_AUTO);

	lr_start_transaction("itinerary");
	web_custom_request("welcome.pl_2", 
		"URL=http://{HOST_PORT}/cgi-bin/welcome.pl?page=itinerary", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t41.inf", 
		"Mode=HTTP", 
		LAST);

	     web_reg_save_param_ex(
        "ParamName=flightID",
        "LB=input type=\"hidden\" name=\"flightID\" value=\"",
        "RB=\"",
        "Ordinal=ALL",
        "NotFound=warning",
        SEARCH_FILTERS,
        LAST);
	
	
	web_custom_request("itinerary.pl", 
		"URL=http://{HOST_PORT}/cgi-bin/itinerary.pl", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t42.inf", 
		"Mode=HTTP", 
		LAST);

	

	web_custom_request("nav.pl_3", 
		"URL=http://{HOST_PORT}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t43.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("itinerary",LR_AUTO);

//----------- создаем запрос на удаление
	arrSize = lr_paramarr_len("flightID");
	lr_save_string("", "request");
	lr_save_string("", "cgifieds_concat");

	for (i = 1; i <= arrSize; i++) {
    	lr_save_string(lr_paramarr_idx("flightID", i), "temp_Body");
    	lr_save_int(i, "temp_i");
    	lr_save_string(lr_eval_string("&.cgifields={temp_i}"), "temp_cgifields");
    	lr_save_string(lr_eval_string("{cgifields_concat}{temp_cgifields}"), "cgifields_concat");
    	lr_save_string(lr_eval_string("{request}&flightID={temp_Body}"), "temp_request");
    	lr_save_string(lr_eval_string("{temp_request}"), "request");
}
//----------- создаем запрос на удаление
	
	lr_start_transaction("cancel_booking");


	web_add_header("Origin", 
		"http://{HOST_PORT}");

	if (arrSize) {
	  	web_reg_find("Fail=Found",
		"Search=Body",
		"Text=database synchronization error",
		LAST);
	}
	
	web_reg_find("Fail=Found",
		"Search=Body",
		"Text={flightID_1}",
		LAST);
	
	web_custom_request("itinerary.pl_2", 
		"URL=http://{HOST_PORT}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/itinerary.pl", 
		"Snapshot=t51.inf", 
		"Mode=HTTP", 
		"Body=1=on{request}&removeFlights.x=65&removeFlights.y=8{cgifields_concat}",
		LAST);

	lr_end_transaction("cancel_booking",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("signoff");

	web_reg_find("Search=All",
		"Text=A Session ID has been created and loaded into a cookie",
		LAST);

	web_custom_request("welcome.pl_3", 
		"URL=http://{HOST_PORT}/cgi-bin/welcome.pl?signOff=1", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t52.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("home.html_2", 
		"URL=http://{HOST_PORT}/WebTours/home.html", 
		"Method=GET", 
		"Resource=0", 
		"Referer=http://{HOST_PORT}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t55.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("nav.pl_4", 
		"URL=http://{HOST_PORT}/cgi-bin/nav.pl?in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t56.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("signoff",LR_AUTO);
		lr_end_transaction("UC05_Cancel_Booking",LR_AUTO);

	return 0;
}