Action()
{
	struct Field{
		char name[STR_LEN];
		char value[STR_LEN];
	};
	
	struct Radio{
		char name[STR_LEN];
		char values[10][STR_LEN];
	};
	
	struct Field FormFields[10];
	struct Radio RadioGroups[10];
	
	int iT, iR, iS;

	char tmpTextFields[10][STR_LEN];
	
	char tmpRadioFields[30][STR_LEN];
	
    char tmpSelectFields[20][STR_LEN];
    
    char nameFields[10][64];
    char valueFields[10][64];

    web_set_max_html_param_len("1024");
    	
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

    find_elements();

	lr_continue_on_error(1);
	
	web_link("Start test", 
		"Text=Start test", 
		"Snapshot=t16.inf",
		LAST);

    lr_continue_on_error(0);
    
    for (iT = 1; iT <= atoi(lr_eval_string("{Text_count}")) ; iT++)
    {
		sprintf(tmpTextFields[iT], "{Text_%d}", iT);
		strcpy(FormFields[iT].name, "Name=");
		strcat(FormFields[iT].name, lr_eval_string(tmpTextFields[iT]));
		strcpy(FormFields[iT].value, "Value=test");
		lr_output_message(FormFields[iT].name);
    }
    
    for (iR = 1; iR <= atoi(lr_eval_string("{Radio_count}")) ; iR++)
    {
    	int radioCount = 1;
    	int radioValues = 0;
    	char tmpStr[STR_LEN];
    	char currentRadioName[STR_LEN];
    	char nextRadioName[STR_LEN];
    	sprintf(tmpRadioFields[iR], "{Radio_%d}", iR);
    	strcpy(tmpStr, lr_eval_string(tmpRadioFields[iR]));
    	
    	lr_save_param_regexp(
    		tmpStr,
    	    strlen(tmpStr),
    	    "Ordinal=1",
    	    "RegExp=\"name\"=\".*?\"",
    	    "ResultParam=reMatchesRadioName",
        	LAST
    	);
    	
    	if (strcmp (currentRadioName, lr_eval_string("{reMatchesRadioName}"))!=0)
    	{
    		strcpy(RadioGroups[radioCount].name, lr_eval_string("{reMatchesRadioName}"));
    		strcpy(currentRadioName, RadioGroups[radioCount].name);
    		radioCount++;
    		radioValues = 0;
    	}
    	
    	lr_save_param_regexp(
    		tmpStr,
    	    strlen(tmpStr),
    	    "Ordinal=1",
    	    "RegExp=\"value\"=\".*?\"",
    	    "ResultParam=reMatchesRadioValue",
        	LAST
    	);
    	
    	strcpy(RadioGroups[radioCount-1].values[radioValues], lr_eval_string("reMatchesRadioValue"));
    	radioValues++;
    	
    }
        
    strcpy (FormFields[iT].name, "LAST");

	web_reg_find("Text=Question 2", 
		LAST);

	web_submit_data("1",
        "Action=http://test.youplace.net/question/1",
        "Method=POST",
		"Snapshot=t17.inf",
		ITEMDATA,
		FormFields[1].name, FormFields[1].value, ENDITEM,
		FormFields[2].name, FormFields[2].value, ENDITEM,
		FormFields[3].name, FormFields[3].value, ENDITEM,
		FormFields[4].name, FormFields[4].value, ENDITEM,
		FormFields[5].name, FormFields[5].value, ENDITEM,
		FormFields[6].name, FormFields[6].value, ENDITEM,
		FormFields[7].name, FormFields[7].value, ENDITEM,
		FormFields[8].name, FormFields[8].value, ENDITEM,
		FormFields[9].name, FormFields[9].value, ENDITEM,
		FormFields[10].name, FormFields[10].value, ENDITEM,
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