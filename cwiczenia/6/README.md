```
function longestWord(string) {
    curr_len = 0
    max_len = 0
    longestString = ""
    lastChar = ' '
  
    for (i = 0; i < strlen(string); i++) {
        if (!isspace(string[i]) && !ispunct(string[i])) {
            curr_len++;
        } else {
            if (curr_len > max_len) {
                max_len = curr_len;
                longestString = string.substr(i - curr_len, curr_len);
            }
            curr_len = 0;
        }
    }
    if(curr_len > max_len) {
       max_len = curr_len;
       longestString = string.substr(i - curr_len, curr_len);
    }
    return longestString;
}

}

function deleteWord(string, key) {
    i = 0
    newString = ""
    stringstream check1(string);
    while (getline(check1, word, ' ')) {
        if (word != key) {
            newString += word;
            newString += " ";
        }
    }
    return newString;
}

```
