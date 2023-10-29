Action()
{
	lr_start_transaction("UC06_Регистрация_новых_пользователей");
	lr_start_transaction("welcome");
	
	
    lr_save_string(lr_eval_string("{MyHex}{MyHex}-{MyHex}-{MyHex}-{MyHex}-{MyHex}{MyHex}{MyHex}"), "username");

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

	lr_start_transaction("user_registration_form");


	web_url("login.pl", 
		"URL=http://{HOST_PORT}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/WebTours/home.html", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);


	lr_end_transaction("user_registration_form",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("register_new_user");
	
		web_add_header("Origin", 
		"http://{HOST_PORT}");


	web_reg_find("Search=Body",
		"Text={username}",
		LAST);

	web_submit_data("login.pl_2", 
		"Action=http://{HOST_PORT}/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value=q1", ENDITEM, 
		"Name=passwordConfirm", "Value=q1", ENDITEM, 
		"Name=firstName", "Value=first_name", ENDITEM, 
		"Name=lastName", "Value=last_name", ENDITEM, 
		"Name=address1", "Value=street_address", ENDITEM, 
		"Name=address2", "Value=city_state_zip", ENDITEM, 
		"Name=register.x", "Value=40", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

		lr_end_transaction("register_new_user",LR_AUTO);
	
		lr_think_time(5);

	lr_start_transaction("new_user_saluations");

	web_reg_find("Search=Body",
		"Text=Don't forget to sign off when",
		LAST);

	web_url("welcome.pl", 
		"URL=http://{HOST_PORT}/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/login.pl", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("new_user_saluations",LR_AUTO);
	
			lr_think_time(5);

	lr_start_transaction("signoff");

	
	web_reg_find("Search=All",
	"Text=A Session ID has been created",
	LAST);

	web_url("SignOff Button", 
		"URL=http://{HOST_PORT}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{HOST_PORT}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("signoff",LR_AUTO);
	lr_end_transaction("UC06_Регистрация_новых_пользователей",LR_AUTO);

	return 0;
}