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
	
	struct Select{
		char name[STR_LEN];
		char values[10][STR_LEN];
		char maxValue[STR_LEN];
	};
	
	struct Field FormFields[10];
	struct Radio RadioGroups[10];
	struct Select SelectBoxes[10];
	
	int iT, iR, iS, i, j;

	char tmpTextFields[10][STR_LEN];
	
	char tmpRadioName[30][STR_LEN];
	char tmpRadioValue[30][STR_LEN];
	
    char tmpSelectFields[20][STR_LEN];
    
    char nameFields[10][64];
    char valueFields[10][64];
    
    int radioCount = 1;
    int radioValues = 0;
    
    int selectCount = 1;
    int selectValues = 0;
    
    char indexForm[2];
    char url[STR_LEN];
    
    int flag, number = 0;

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
    
    flag = atoi(lr_eval_string("{Text_count}")) + atoi(lr_eval_string("{RadioName_count}")) + atoi(lr_eval_string("{Select_count}"));
    
    while( flag > 0)
	{    	
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
	    
	    selectCount = atoi(lr_eval_string("{Select_count}"));
	                       
	    for (iS = 1; iS <= selectCount; iS++)
	    {
	    	int startPos = 0;
	    	int endPos = 0;
	    	int index, i = 0;
	    	char tmpStr[1024];
	    	sprintf(tmpSelectFields[iS], "{Select_%d}", iS);
	    	strcpy(tmpStr, lr_eval_string(tmpSelectFields[iS]));
	    	
	    	for( index = 0; index < strlen(tmpStr); index++ )
	    	{
	    		if (tmpStr[index] == '"')
	    		{
	    			startPos = index;
	    			while((tmpStr[index+1] != '"') && (index < strlen(tmpStr) - 1))
	    			{
	    				index++;
	    			}
	    			endPos = index;
	    			
	    			
	    			if (startPos == 0)
	    			{
	    				strncpy(SelectBoxes[iS].name, tmpStr+startPos + 1, endPos - startPos);
	    			}
	    			else
	    			{
	    				strncpy(SelectBoxes[iS].values[i], tmpStr+startPos + 1, endPos - startPos);
	    				i++;
	    			}
	    			index++;
	    		}
	    	}
	    	
	    }
	    
	    
	    for (iS = 1; iS <= selectCount; iS++)
	    {
	    	char max[STR_LEN];
	    	strcpy(max,SelectBoxes[iS].values[0]);
	    	for (selectValues = 0; selectValues < 10; selectValues++)
	    	{
	    		if(strlen(SelectBoxes[iS].values[selectValues]) > strlen(max))
	    		{
	    			strcpy(max,SelectBoxes[iS].values[selectValues]);
	    		}
	    		strcpy(SelectBoxes[iS].maxValue, max);
	    	}
	    }
	
	    j = selectCount;
	    for (iT = i; iT < i + selectCount; iT++)
	    {
			strcpy(FormFields[iT].name, "Name=");
			strcat(FormFields[iT].name, SelectBoxes[j].name);
			strcpy(FormFields[iT].value, "Value=");
			strcat(FormFields[iT].value, SelectBoxes[j].maxValue);
			lr_output_message(FormFields[iT].name);
			lr_output_message(FormFields[iT].value);
			strcpy(SelectBoxes[j].maxValue, "/0");
			j--;
	    }
	    
    	strcpy(FormFields[iT].name, "LAST");
    	
    	find_elements();
    	
    	number++;
    	sprintf(indexForm, "%d", number);
    	sprintf(url, "Action=http://test.youplace.net/question/%d", number);
    	
    	lr_continue_on_error(1);
    	web_submit_data(indexForm,
	        url,
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
		selectCount = 1;
		selectCount = 0;
	
		lr_continue_on_error(0);
		
		flag = atoi(lr_eval_string("{Text_count}")) + atoi(lr_eval_string("{RadioName_count}")) + atoi(lr_eval_string("{Select_count}"));
    }

	return 0;
}