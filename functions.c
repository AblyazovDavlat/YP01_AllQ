void find_elements()
{
	web_reg_save_param("Text", 
        "LB/IC=<input type=\"text\" name=\"", 
        "RB/IC=\">",
        "Ord=ALL", 
        "Search=body", 
        LAST);
    
	web_reg_save_param("Radio", 
        "LB/IC=<input type=\"radio\" ", 
        "RB/IC=\">",
        "Ord=ALL", 
        "Search=body", 
        LAST);
      
	web_reg_save_param("Select", 
        "LB/IC=<select ", 
        "RB/IC=\/select>",
        "Ord=ALL", 
        "Search=body", 
        LAST);	
}

void resolve_radio(char** radioArray, int size)
{
	
}