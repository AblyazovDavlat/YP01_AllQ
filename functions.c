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