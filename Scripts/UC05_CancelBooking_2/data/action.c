Action()
{

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_custom_request("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_custom_request("header.html", 
		"URL=http://localhost:1080/webtours/header.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/webtours/", 
		"Snapshot=t2.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("DNT");

	web_revert_auto_header("Sec-Fetch-Mode");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_custom_request("canonical.html", 
		"URL=http://detectportal.firefox.com/canonical.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_custom_request("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/webtours/", 
		"Snapshot=t4.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_custom_request("hp_logo.png", 
		"URL=http://localhost:1080/webtours/images/hp_logo.png", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://localhost:1080/webtours/header.html", 
		"Snapshot=t5.inf", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_custom_request("home.html", 
		"URL=http://localhost:1080/WebTours/home.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t6.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_custom_request("webtours.png", 
		"URL=http://localhost:1080/webtours/images/webtours.png", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://localhost:1080/webtours/header.html", 
		"Snapshot=t7.inf", 
		LAST);

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_custom_request("nav.pl", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t8.inf", 
		"Mode=HTTP", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_custom_request("mer_login.gif", 
		"URL=http://localhost:1080/WebTours/images/mer_login.gif", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t9.inf", 
		LAST);

	web_revert_auto_header("DNT");

	web_revert_auto_header("Sec-Fetch-Site");

	web_custom_request("success.txt", 
		"URL=http://detectportal.firefox.com/success.txt?ipv4", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t10.inf", 
		LAST);

	web_custom_request("canonical.html_2", 
		"URL=http://detectportal.firefox.com/canonical.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("success.txt_2", 
		"URL=http://detectportal.firefox.com/success.txt?ipv4", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t12.inf", 
		LAST);

	web_custom_request("canonical.html_3", 
		"URL=http://detectportal.firefox.com/canonical.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t13.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("success.txt_3", 
		"URL=http://detectportal.firefox.com/success.txt?ipv6", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t14.inf", 
		LAST);

	web_custom_request("success.txt_4", 
		"URL=http://detectportal.firefox.com/success.txt?ipv4", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t15.inf", 
		LAST);

	web_custom_request("canonical.html_4", 
		"URL=http://detectportal.firefox.com/canonical.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("success.txt_5", 
		"URL=http://detectportal.firefox.com/success.txt?ipv4", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t17.inf", 
		LAST);

	web_custom_request("success.txt_6", 
		"URL=http://detectportal.firefox.com/success.txt?ipv6", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t18.inf", 
		LAST);

	web_custom_request("canonical.html_5", 
		"URL=http://detectportal.firefox.com/canonical.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t19.inf", 
		"Mode=HTTP", 
		LAST);

	lr_start_transaction("1_transaction");

	web_custom_request("success.txt_7", 
		"URL=http://detectportal.firefox.com/success.txt?ipv4", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t20.inf", 
		LAST);

	web_custom_request("success.txt_8", 
		"URL=http://detectportal.firefox.com/success.txt?ipv6", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t21.inf", 
		LAST);

	web_custom_request("canonical.html_6", 
		"URL=http://detectportal.firefox.com/canonical.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t22.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("success.txt_9", 
		"URL=http://detectportal.firefox.com/success.txt?ipv4", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t23.inf", 
		LAST);

	web_custom_request("success.txt_10", 
		"URL=http://detectportal.firefox.com/success.txt?ipv6", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t24.inf", 
		LAST);

	web_custom_request("canonical.html_7", 
		"URL=http://detectportal.firefox.com/canonical.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t25.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("success.txt_11", 
		"URL=http://detectportal.firefox.com/success.txt?ipv4", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t26.inf", 
		LAST);

	web_custom_request("success.txt_12", 
		"URL=http://detectportal.firefox.com/success.txt?ipv6", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t27.inf", 
		LAST);

	lr_end_transaction("1_transaction",LR_AUTO);

	web_custom_request("canonical.html_8", 
		"URL=http://detectportal.firefox.com/canonical.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t28.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("success.txt_13", 
		"URL=http://detectportal.firefox.com/success.txt?ipv4", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t29.inf", 
		LAST);

	web_custom_request("success.txt_14", 
		"URL=http://detectportal.firefox.com/success.txt?ipv6", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t30.inf", 
		LAST);

	web_add_auto_header("DNT", 
		"1");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(7);

	web_custom_request("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t31.inf", 
		"Mode=HTTP", 
		"Body=userSession=137588.308707979HAHHVQipzcQVzzzHtctzDpVQVHHf&username=user11&password=q1&login.x=49&login.y=7&JSFormSubmit=off", 
		LAST);

	web_custom_request("login.pl_2", 
		"URL=http://localhost:1080/cgi-bin/login.pl?intro=true", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t32.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("nav.pl_2", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t33.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_custom_request("itinerary.gif", 
		"URL=http://localhost:1080/WebTours/images/itinerary.gif", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t34.inf", 
		LAST);

	web_custom_request("in_home.gif", 
		"URL=http://localhost:1080/WebTours/images/in_home.gif", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t35.inf", 
		LAST);

	web_custom_request("signoff.gif", 
		"URL=http://localhost:1080/WebTours/images/signoff.gif", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t36.inf", 
		LAST);

	web_custom_request("flights.gif", 
		"URL=http://localhost:1080/WebTours/images/flights.gif", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t37.inf", 
		LAST);

	web_revert_auto_header("DNT");

	web_revert_auto_header("Sec-Fetch-Dest");

	web_revert_auto_header("Sec-Fetch-Mode");

	web_revert_auto_header("Sec-Fetch-Site");

	web_custom_request("canonical.html_9", 
		"URL=http://detectportal.firefox.com/canonical.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t38.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("success.txt_15", 
		"URL=http://detectportal.firefox.com/success.txt?ipv4", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t39.inf", 
		LAST);

	web_custom_request("success.txt_16", 
		"URL=http://detectportal.firefox.com/success.txt?ipv6", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t40.inf", 
		LAST);

	lr_start_transaction("2_transaction");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(4);

	web_custom_request("welcome.pl_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t41.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("itinerary.pl", 
		"URL=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t42.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("nav.pl_3", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t43.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_custom_request("in_itinerary.gif", 
		"URL=http://localhost:1080/WebTours/images/in_itinerary.gif", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t44.inf", 
		LAST);

	web_custom_request("cancelreservation.gif", 
		"URL=http://localhost:1080/WebTours/images/cancelreservation.gif", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t45.inf", 
		LAST);

	web_custom_request("home.gif", 
		"URL=http://localhost:1080/WebTours/images/home.gif", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t46.inf", 
		LAST);

	web_custom_request("cancelallreservations.gif", 
		"URL=http://localhost:1080/WebTours/images/cancelallreservations.gif", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t47.inf", 
		LAST);

	lr_end_transaction("2_transaction",LR_AUTO);

	lr_start_transaction("3_transaction");

	web_revert_auto_header("DNT");

	web_revert_auto_header("Sec-Fetch-Dest");

	web_revert_auto_header("Sec-Fetch-Mode");

	web_revert_auto_header("Sec-Fetch-Site");

	lr_think_time(15);

	web_custom_request("canonical.html_10", 
		"URL=http://detectportal.firefox.com/canonical.html", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t48.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("success.txt_17", 
		"URL=http://detectportal.firefox.com/success.txt?ipv4", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t49.inf", 
		LAST);

	web_custom_request("success.txt_18", 
		"URL=http://detectportal.firefox.com/success.txt?ipv6", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t50.inf", 
		LAST);

	web_add_auto_header("DNT", 
		"1");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_custom_request("itinerary.pl_2", 
		"URL=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t51.inf", 
		"Mode=HTTP", 
		"Body=1=on&flightID=78557491-789-uq&flightID=78557417-1559-uq&flightID=78557526-2325-uq&flightID=78557526-3094-uq&flightID=78557491-3866-uq&flightID=78557491-4635-uq&flightID=78557526-5401-uq&flightID=78557491-6173-uq&flightID=78557491-6943-uq&flightID=78557491-7712-uq&flightID=78557491-8481-uq&flightID=78557491-9250-uq&flightID=78557491-10020-uq&flightID=78557491-10789-uq&flightID=78557491-11558-uq&flightID=78557526-12325-uq&flightID=78557417-13098-uq&flightID=78557526-13863-uq&flightID="
		"78557491-14635-uq&flightID=78557453-15403-uq&flightID=78557491-16173-uq&flightID=78557417-16944-uq&flightID=78557453-17711-uq&flightID=78557491-18481-uq&flightID=78557526-19248-uq&flightID=78557526-20017-uq&flightID=78557526-20786-uq&flightID=78557417-21559-uq&flightID=78557526-22325-uq&flightID=78557453-23095-uq&flightID=78557526-23863-uq&flightID=78557453-24634-uq&flightID=78557417-25405-uq&flightID=78557526-26171-uq&flightID=78557491-26943-uq&flightID=78557526-27709-uq&flightID="
		"78557491-28481-uq&flightID=78557491-29250-uq&flightID=78557453-30018-uq&flightID=78557417-30790-uq&flightID=78557417-31559-uq&flightID=78557417-32328-uq&flightID=78557491-33096-uq&flightID=78557526-33863-uq&flightID=78557526-34632-uq&flightID=78557417-35405-uq&flightID=78557453-36172-uq&flightID=78557491-36943-uq&flightID=78557526-37709-uq&flightID=78557453-38480-uq&flightID=78557453-39249-uq&flightID=78557526-40017-uq&flightID=78557526-40786-uq&flightID=78557417-41559-uq&flightID="
		"78557417-42328-uq&flightID=78557417-43098-uq&flightID=78557526-43863-uq&flightID=78557417-44636-uq&flightID=78557526-45401-uq&flightID=78557526-46171-uq&flightID=78557491-46943-uq&flightID=78557491-47712-uq&flightID=78557453-48480-uq&flightID=78557417-49251-uq&flightID=78557491-50020-uq&flightID=78557417-50790-uq&flightID=78557417-51559-uq&flightID=78557417-52328-uq&flightID=78557417-53098-uq&flightID=78557491-53866-uq&flightID=78557417-54636-uq&flightID=78557417-55405-uu&removeFlights.x=65&"
		"removeFlights.y=8&.cgifields=33&.cgifields=32&.cgifields=63&.cgifields=21&.cgifields=71&.cgifields=7&.cgifields=26&.cgifields=18&.cgifields=72&.cgifields=16&.cgifields=44&.cgifields=55&.cgifields=27&.cgifields=57&.cgifields=61&.cgifields=20&.cgifields=10&.cgifields=31&.cgifields=35&.cgifields=11&.cgifields=48&.cgifields=65&.cgifields=29&.cgifields=50&.cgifields=39&.cgifields=64&.cgifields=58&.cgifields=41&.cgifields=12&.cgifields=15&.cgifields=52&.cgifields=60&.cgifields=56&.cgifields=66&"
		".cgifields=45&.cgifields=19&.cgifields=62&.cgifields=54&.cgifields=67&.cgifields=70&.cgifields=68&.cgifields=2&.cgifields=17&.cgifields=1&.cgifields=30&.cgifields=25&.cgifields=28&.cgifields=40&.cgifields=14&.cgifields=69&.cgifields=59&.cgifields=49&.cgifields=24&.cgifields=53&.cgifields=22&.cgifields=42&.cgifields=46&.cgifields=23&.cgifields=13&.cgifields=6&.cgifields=3&.cgifields=36&.cgifields=9&.cgifields=51&.cgifields=47&.cgifields=8&.cgifields=38&.cgifields=4&.cgifields=34&.cgifields=37&"
		".cgifields=43&.cgifields=5", 
		LAST);

	lr_end_transaction("3_transaction",LR_AUTO);

	lr_think_time(25);

	lr_start_transaction("4_transaction");

	web_custom_request("welcome.pl_3", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t52.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_custom_request("home.html_2", 
		"URL=http://localhost:1080/WebTours/home.html", 
		"Method=GET", 
		"Resource=0", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t55.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("nav.pl_4", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t56.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("4_transaction",LR_AUTO);

	return 0;
}