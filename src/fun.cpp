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
    bool capital = false;
    bool problem = false;
    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            if(capital && !problem)
            {
                result++;
            }
            capital = false;
            problem = false;
        }
        else if(64<str[i] && str[i]<91)
        {
            if(capital)
            {
                problem = true;
            }
            else
            {
                capital = true;
            }
        }
        else if (str[i]<96 || str[i] > 123)
        {
            problem = true;
        }
        i++;
    }
    if (capital && !problem){result++;}
    return result;
}
unsigned int faStr3(const char *str)
{
    double average = 0.0;
    int i = 0;
    int words = 0;
    int sum = 0;
    bool inWord = false;

    while(str[i] != '\0')
    {
        if(!inWord && str[i] != ' ')
        {
            inWord = true;
            sum++;
            words++;
        }
        else if (inWord && str[i] != ' ')
        {
            sum++;
        }
        else
        {
            inWord = false;
            average += sum;
            sum = 0;
        }
        i++;
    }
    if(inWord)
        average += sum;
    average /= words;
    int r_sum = average;
    if(average - r_sum >= 0.5)
       r_sum++;

    return r_sum;
}