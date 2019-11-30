struct Field{
	char name[STR_LEN];
	char value[STR_LEN];
};

struct Radio{
	char name[STR_LEN];
	char values[10][STR_LEN];
	char max_value[STR_LEN];
};

struct Select{
	char name[STR_LEN];
	char values[10][STR_LEN];
	char max_value[STR_LEN];
};

void find_elements()
{
	web_reg_save_param("Text", 
        "LB/IC=<input type=\"text\" name=\"", 
        "RB/IC=\">",
        "Ord=ALL", 
        "Search=body", 
        LAST);
    
	web_reg_save_param("RadioName", 
        "LB/IC=<input type=\"radio\" name=\"", 
        "RB/IC=\"",
        "Ord=ALL", 
        "Search=body", 
        LAST);
	
	web_reg_save_param("RadioValue", 
        "LB/IC=\" value=\"", 
        "RB/IC=\"",
        "Ord=ALL", 
        "Search=body", 
        LAST);
      
	web_reg_save_param("Select", 
        "LB/IC=<select name=", 
        "RB/IC=<\/select>",
        "Ord=ALL", 
        "Search=body", 
        LAST);	
}

void resolve_text_fields(const char* param, const int size, struct Field* output)
{
	int i;
	char tmp_text_params[10][STR_LEN];
	
	for (i = 1; i <= size; i++)
	{
		sprintf(tmp_text_params[i], "%s%s%d%s", param, "_", i, "}");
		
		strcpy(output[i].name, "Name=");
		strcat(output[i].name, lr_eval_string(tmp_text_params[i]));
		strcpy(output[i].value, "Value=test");
		lr_output_message(output[i].name);
	}
}

int resolve_radio_fields(const char* radio_name, const char* radio_value, const int size, struct Radio* output)
{
	int i, j;
	int count_radio_groups = 0;
	int count_values_per_group[10] = {0};
	
	char tmp_name[STR_LEN];
	char tmp_value[STR_LEN];
	char current_radio_name[STR_LEN];
	
	char tmp_radio_names[30][STR_LEN];
	char tmp_radio_values[30][STR_LEN];
	
	for (i = 1; i <= size; i++)
	{
		sprintf(tmp_radio_names[i], "%s%s%d%s", radio_name, "_", i, "}");
		strcpy(tmp_name, lr_eval_string(tmp_radio_names[i]));
		
		sprintf(tmp_radio_values[i], "%s%s%d%s", radio_value, "_", i, "}");
		strcpy(tmp_value, lr_eval_string(tmp_radio_values[i]));
		
		if (strcmp(current_radio_name, tmp_name)!= 0)
		{
			count_radio_groups++;
			
			strcpy(output[count_radio_groups].name, tmp_name);
			strcpy(current_radio_name, output[count_radio_groups].name);
			count_values_per_group[count_radio_groups] = 0;
		}
		
		strcpy(output[count_radio_groups].values[count_values_per_group[count_radio_groups]], tmp_value);
		count_values_per_group[count_radio_groups]++;
	}
	
	for (i = 1; i <= count_radio_groups; i++)
	{
		char max[STR_LEN];
		strcpy(max, output[i].values[0]);
			
		for (j = 0; j < count_values_per_group[i]; j++)
		{
			if(strlen(output[i].values[j]) > strlen(max))
	    	{
	    		strcpy(max,output[i].values[j]);
	    	}
		}
		strcpy(output[i].max_value, max);
	}
	
	return count_radio_groups;
}

void resolve_select_fields(const char* select_name, const int size, struct Select* output)
{
	int start_pos = 0;
	int index, i, j = 0;
	
	int count_values_per_box[10] = {0};
		
	char tmp_select_fields[10][STR_LEN];
	char tmp_str[1024];
	
	for (i = 1; i <= size; i++)
	{
			
		sprintf(tmp_select_fields[i], "%s%s%d%s", select_name, "_", i, "}");
		strcpy(tmp_str, lr_eval_string(tmp_select_fields[i]));
		
		count_values_per_box[i] = 0;
		
		for (index = 0; index < strlen(tmp_str); index++)
		{
			if (tmp_str[index] == '"')
			{

			}
		}	
	}
	
	for (i = 1; i <= size; i++)
    {
    	char max[STR_LEN];
    	strcpy(max,output[i].values[0]);
    	
    	for (j = 0; j < count_values_per_box[i]; j++)
    	{
    		if(strlen(output[i].values[j]) > strlen(max))
    		{
    			strcpy(max,output[i].values[j]);
    		}   		
    	}
    	strcpy(output[i].max_value, max);
    	lr_output_message(output[i].max_value);
    }
}

Action()
{	
	
	struct Field *FormFields;
	struct Radio *RadioGroups;
	struct Select *SelectBoxes;
	
	int count_resolved_radios = 0;
	int count_resolved_items = 0;
	int count_all_resolved_items = 0;
	
	int count_elements = 0;
	int count_text_fields = 0;
	int count_radio_elements = 0;
	int count_select_elements = 0;
	
	int i, j;
    
    char indexForm[2];
    char url[STR_LEN];
    
    int number = 0;
    
    FormFields = (struct Field*)malloc(sizeof(struct Field) * 10);
    RadioGroups = (struct Radio*)malloc(sizeof(struct Radio) * 10);
    SelectBoxes = (struct Select*)malloc(sizeof(struct Select) * 10);

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
    
    count_elements = atoi(lr_eval_string("{Text_count}")) + atoi(lr_eval_string("{RadioName_count}")) + atoi(lr_eval_string("{Select_count}"));
    
    while( count_elements > 0 )
	{ 
		memset(FormFields, "", 10 * sizeof(struct Field));
		memset(RadioGroups, "", 10 * sizeof(struct Radio));
		memset(SelectBoxes, "", 10 * sizeof(struct Select));   	
    	count_text_fields = atoi(lr_eval_string("{Text_count}"));                         
    	resolve_text_fields("{Text", count_text_fields, FormFields);
		
    	count_radio_elements = atoi(lr_eval_string("{RadioName_count}"));
    	count_resolved_radios = resolve_radio_fields("{RadioName", "{RadioValue", count_radio_elements, RadioGroups);
    	
    	count_resolved_items = count_text_fields + count_resolved_radios;

    	for (i = count_text_fields + 1; i <= count_resolved_items; i++)
    	{
    		strcpy(FormFields[i].name, "Name=");
			strcat(FormFields[i].name, RadioGroups[count_resolved_radios].name);
			strcpy(FormFields[i].value, "Value=");
			strcat(FormFields[i].value, RadioGroups[count_resolved_radios].max_value);
			lr_output_message(FormFields[i].name);
			lr_output_message(FormFields[i].value);
			count_resolved_radios--;
    	}

	    count_select_elements = atoi(lr_eval_string("{Select_count}"));
	    resolve_select_fields("{Select", count_select_elements, SelectBoxes);
	
	    count_all_resolved_items = count_resolved_items + count_select_elements;
	    for (i = count_resolved_items + 1; i <= count_all_resolved_items; i++)
	    {
			strcpy(FormFields[i].name, "Name=");
			strcat(FormFields[i].name, SelectBoxes[count_select_elements].name);
			strcpy(FormFields[i].value, "Value=");
			strcat(FormFields[i].value, SelectBoxes[count_select_elements].max_value);
			lr_output_message(FormFields[i].name);
			lr_output_message(FormFields[i].value);
			count_select_elements--;
	    }
	    
    	strcpy(FormFields[count_all_resolved_items + 1].name, "LAST");
    	
    	find_elements();
    	
    	number++;
    	sprintf(indexForm, "%d", number);
    	sprintf(url, "Action=http://test.youplace.net/question/%d", number);
    	
    	for(i = 1; i <=10 ; i++)
    	{
    		lr_output_message(FormFields[i].name);
			lr_output_message(FormFields[i].value);
    	}
    	
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
	
		lr_continue_on_error(0);
		
		count_elements = atoi(lr_eval_string("{Text_count}")) + atoi(lr_eval_string("{RadioName_count}")) + atoi(lr_eval_string("{Select_count}"));
		
		count_resolved_radios = 0;
		count_resolved_items = 0;
		count_all_resolved_items = 0;
	
		count_text_fields = 0;
		count_radio_elements = 0;
		count_select_elements = 0;
    }
	
    free(FormFields);
	free(RadioGroups);
	free(SelectBoxes);
	
    lr_think_time(5000);
    
	return 0;
}