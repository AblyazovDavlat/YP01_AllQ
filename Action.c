Action()
{
	struct Field{
		char name[STR_LEN];
		char value[STR_LEN];
	};
	
	struct Radio{
		char name[STR_LEN];
		char values[10][STR_LEN];
		char maxValue[STR_LEN];
	};
	
	struct Field FormFields[10];
	struct Radio RadioGroups[10];
	
	int iT, iR, iS, i, j;

	char tmpTextFields[10][STR_LEN];
	
	char tmpRadioName[30][STR_LEN];
	char tmpRadioValue[30][STR_LEN];
	
    char tmpSelectFields[20][STR_LEN];
    
    char nameFields[10][64];
    char valueFields[10][64];
    
    int radioCount = 1;
    int radioValues = 0;

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
    

    for (iR = 1; iR <= atoi(lr_eval_string("{RadioName_count}")) ; iR++)
    {
    	char tmpName[STR_LEN];
    	char tmpValue[STR_LEN];
    	char currentRadioName[STR_LEN];
    	
    	sprintf(tmpRadioName[iR], "{RadioName_%d}", iR);
    	strcpy(tmpName, lr_eval_string(tmpRadioName[iR]));
    	
    	sprintf(tmpRadioValue[iR], "{RadioValue_%d}", iR);
    	strcpy(tmpValue, lr_eval_string(tmpRadioValue[iR]));
    	
    	if (strcmp(currentRadioName, tmpName)!=0)
    	{
    		strcpy(RadioGroups[radioCount].name, tmpName);
    		strcpy(currentRadioName, RadioGroups[radioCount].name);
    		radioCount++;
    		radioValues = 0;
    	}
    	
    	strcpy(RadioGroups[radioCount-1].values[radioValues], tmpValue);
    	radioValues++;
    }
    
    for (iR = 1; iR < radioCount; iR++){
    	char max[STR_LEN];
    	strcpy(max,RadioGroups[iR].values[0]);
    	for (radioValues = 0; radioValues < 10; radioValues++)
    	{
    		if(strlen(RadioGroups[iR].values[radioValues]) > strlen(max))
    		{
    			strcpy(max,RadioGroups[iR].values[radioValues]);
    		}
    		strcpy(RadioGroups[iR].maxValue, max);
    	}
    }
    
    j = radioCount - 1;
    for (i = iT; i < iT + radioCount - 1; i++)
    {
		strcpy(FormFields[i].name, "Name=");
		strcat(FormFields[i].name, RadioGroups[j].name);
		strcpy(FormFields[i].value, "Value=");
		strcat(FormFields[i].value, RadioGroups[j].maxValue);
		lr_output_message(FormFields[i].name);
		lr_output_message(FormFields[i].value);
		j--;
    }
    
    for (iS = 1; iS <= atoi(lr_eval_string("{Select_count}")) ; iS++)
    {
    	char tmpStr[1024];
    	char** matchedStr;
    	sprintf(tmpSelectFields[iS], "{Select_%d}", iS);
    	strcpy(tmpStr, lr_eval_string(tmpSelectFields[iS]));
    	matchedStr = str_split(tmpStr, '\"');
    	if (matchedStr)
    	{
       		int i;
        	for (i = 0; *(matchedStr + i); i++)
        	{
            	lr_output_message(*(matchedStr + i));
        	}
    	}
    }
    
    strcpy(FormFields[i].name, "LAST");

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
    
    radioCount = 1;
    radioValues = 0;

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