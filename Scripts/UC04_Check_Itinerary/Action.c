Action()
{ 
	lr_start_transaction("UC04_ќзнакомление с путевым листом");

	lr_start_transaction("welcome");
/*Correlation comment - Do not change!  Original value='137567.211178615HAHzVVDptcftctfzpziAff' Name ='userSession' Type ='ResponseBased'*/
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

	lr_think_time(5);

	lr_start_transaction("login");
	
	web_add_header("Origin", 
		"http://{HOST_PORT}");


	web_reg_find("Search=All",
		"Text=User password was correc",
		LAST);

	web_submit_data("login.pl",
		"Action=http://{HOST_PORT}/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{HOST_PORT}/cgi-bin/nav.pl?in=home",
		"Snapshot=t56.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={usernamelogin}", ENDITEM,
		"Name=password", "Value={userpassword}", ENDITEM,
		"Name=login.x", "Value=30", ENDITEM,
		"Name=login.y", "Value=7", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);
	
	lr_end_transaction("login",LR_AUTO);

		lr_think_time(5);

	lr_start_transaction("itinerary");

	web_reg_find("Search=All",
		"Text= User wants the intineraries",
		LAST);

	web_url("welcome.pl", 
		"URL=http://{HOST_PORT}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t59.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("itinerary",LR_AUTO);

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
		"Referer=http://{HOST_PORT}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t64.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("signoff",LR_AUTO);
	lr_end_transaction("UC04_ќзнакомление с путевым листом",LR_AUTO);

	return 0;
}