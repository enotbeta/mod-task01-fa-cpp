unsigned int faStr1(const char *str)
{
    unsigned int result = 0;
    int i = 0;
    bool is_word = false;
    bool has_digit = false;  
    while(str[i] != '\0')
    {
        if (str[i] == ' ') // if it is the end of a word
        {
            if(is_word && !has_digit)
            {
                result++; //+ 1 word
            }
            has_digit = false;
            is_word = false;
        }
        if(str[i] > 64 && str[i] < 123) // letter
        {
            is_word = true;
        }
        if(str[i]< 58 && str[i] > 47) // digit
        {
            has_digit = true;
        }
        i++;
    }
    if(is_word && !has_digit) {result++;} // check the last word
    return result;
}
unsigned int faStr2(const char *str)
{
    unsigned int result = 0;
    int i = 0;
    bool is_word = false;
    bool has_digit = false;
    while(str[i] != '\0')
    {
        if (str[i] == ' ') // if it is the end of a word
        {
            if(is_word && !has_digit)
            {
                result++; //+ 1 word
                is_word = false; //restore flag
            }
        }
        if(str[i] > 64 && str[i] < 91) // uppercase
        {
            if (is_word == true) {has_digit = false;} // double uppercase
            else {is_word = true;}
        }
        if(str[i]< 58 && str[i] > 47) // digit
        {
            has_digit = true;
        }
        i++;
    }
    if(is_word && !has_digit) {result++;} // check the last word
    return result;
}
unsigned int faStr3(const char *str)
{
    int i = 0;
    bool is_word = false;
    int counter = 0;
    int sum = -1; //because last char
    while(str[i] != '\0')
    {
        if(is_word == false && str[i] != ' ' )
        {
            counter++;
            sum++;
            is_word = true;
        }
        if(is_word == true && str[i] != ' ')
        {
            sum++;
        }
        if(str[i] == ' ')
        {
            is_word = false;
        }
        i++;
    }
    if(counter == 0)
    {return 0;}
    double result = sum / counter;
    return 0;
}