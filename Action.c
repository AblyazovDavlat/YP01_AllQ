Action()
{
	int instance;
	int i;
    char name[20][32];
    char value[20][32];

	web_reg_find("Text=New Test", 
		LAST);

	web_url("test.youplace.net", 
		"URL=http://test.youplace.net/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_find("Text=Question 1", 
		LAST);

	web_reg_save_param("TextName", 
        "LB/IC=<input type=\"text\" name=\"", 
        "RB/IC=\">",
        "Ord=ALL", 
        "Search=body", 
        LAST);

	web_link("Start test", 
		"Text=Start test", 
		"Snapshot=t16.inf", 
		LAST);
    
    for (instance = 1; instance <= atoi(lr_eval_string("{TextName_count}")) ; instance++)
    {
		sprintf(name[instance], "{TextName_%d}", instance);
		sprintf(value[instance], "%s", lr_eval_string(name[instance]));
		lr_output_message(value[instance]);
    }

	web_reg_find("Text=Question 2", 
		LAST);

	web_submit_form("1", 
		"Snapshot=t17.inf", 
		ITEMDATA, 
		"Name={TextName}", "Value=test", ENDITEM, 
		LAST);

	web_reg_find("Text=Question 3", 
		LAST);

	web_submit_form("2", 
		"Snapshot=t18.inf", 
		ITEMDATA, 
		"Name=PMwaUUYPE5oYfLgR", "Value=6rdm2K84y4gKj40", ENDITEM, 
		"Name=icOQvyqId1KVanQH", "Value=test", ENDITEM, 
		"Name=NLjwu1tvfGhjC1rV", "Value=test", ENDITEM, 
		LAST);

	web_reg_find("Text=Question 4", 
		LAST);

	web_submit_form("3", 
		"Snapshot=t19.inf", 
		ITEMDATA, 
		"Name=vQd3s12phAZIDJWD", "Value=iK1JQSiI5ehnLC", ENDITEM, 
		LAST);

	web_reg_find("Text=Question 5", 
		LAST);

	web_submit_form("4", 
		"Snapshot=t20.inf", 
		ITEMDATA, 
		"Name=SgiWKXil5CgIpS93", "Value=u3muTlY6Gx9l6C9", ENDITEM, 
		"Name=e9RHlNuCoZGAsrXl", "Value=nJ4L1JYT95N9yA", ENDITEM, 
		"Name=t87b2WEhwlhweBa6", "Value=Ek5tSoggyCq2Bqun", ENDITEM, 
		"Name=7CEriolt5bd1jSF2", "Value=test", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_reg_find("Text=Question 6", 
		LAST);

	web_submit_form("5", 
		"Snapshot=t21.inf", 
		ITEMDATA, 
		"Name=ykoK5QlzgjQd40cU", "Value=test", ENDITEM, 
		"Name=hvwWoU8RcFTVE0rV", "Value=CNYqsNwZ64EuC", ENDITEM, 
		LAST);

	web_reg_find("Text=Question 7", 
		LAST);

	web_submit_form("6", 
		"Snapshot=t22.inf", 
		ITEMDATA, 
		"Name=j3MKV6aaGnnAD9a6", "Value=AJFtb3M1ajQm6", ENDITEM, 
		"Name=va9gD49hI7JIYsK8", "Value=gc6de0OqxKVbj", ENDITEM, 
		"Name=vbDjcraz7mww9JCe", "Value=test", ENDITEM, 
		LAST);

	web_reg_find("Text=Question 8", 
		LAST);

	web_submit_form("7", 
		"Snapshot=t23.inf", 
		ITEMDATA, 
		"Name=EiepiWDTq6A2yMCn", "Value=test", ENDITEM, 
		"Name=Z8nWzjta4W1l97aR", "Value=069RWX41uHPb5Q", ENDITEM, 
		LAST);

	web_reg_find("Text=Question 9", 
		LAST);

	web_submit_form("8", 
		"Snapshot=t24.inf", 
		ITEMDATA, 
		"Name=Nfz5NWwsQVyTZPdc", "Value=ULY3APEvUwdKh1", ENDITEM, 
		"Name=sGfrC0mHOnC3rI5P", "Value=rz4ckv2SaHCMZz", ENDITEM, 
		"Name=cO7APX1TCXUkG1nw", "Value=test", ENDITEM, 
		LAST);

	web_reg_find("Text=Test successfully passed", 
		LAST);

	lr_think_time(4);

	web_submit_form("9", 
		"Snapshot=t25.inf", 
		ITEMDATA, 
		"Name=6x2dmWFQCgc2G7zG", "Value=test", ENDITEM, 
		"Name=7pCpqiDRETjhWMD5", "Value=test", ENDITEM, 
		"Name=IXn1NS7DRdMoRrnQ", "Value=9RW7Zyybck66tqiN", ENDITEM, 
		LAST);

	return 0;
}