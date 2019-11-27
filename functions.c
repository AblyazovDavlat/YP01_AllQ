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
        "RB/IC=\">",
        "Ord=ALL", 
        "Search=body", 
        LAST);	
}

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = (char**)malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = (char*)strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = (char*)strdup(token);
            token = (char*)strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}