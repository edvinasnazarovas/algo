## Znaleźć i skasować te same długie słowo w tekście.
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
## Znaleźć ile jest liczb w tekście.
```
function countNumbers(string) {
    int count = 0
    for(int i = 0; i < strlen(string); i++) {
        if(isdigit(string[i])) {
            count++
        }
    }
    return count
}
```
## Znaleźć te same litery w dwoch wzorach.
```
function commonLetters(pattern1, pattern2) {
    char commonLetters[100]
    int commonIndex = 0
    for(int i = 0; i < strlen(pattern1); i++) {
        for(int j = 0; j < strlen(pattern2); j++) {
            if(pattern1[i] == pattern2[j] && !isInArray(commonLetters, commonIndex, pattern1[i])) {
                commonLetters[commonIndex] = pattern1[i]
                commonIndex++
                break
            }
        }
    }
    return commonLetters
}

function isInArray(array, size, value) {
    for(int i = 0; i < size; i++) {
        if(array[i] == value) {
            return true
        }
    }
    return false
}
```
## Wyprowadzić wszystkie nie powtarzające się słowa.
```
function uniqueWords(string) {
    words = string.split(" ")
    uniqueWords = []
    for(int i = 0; i < words.size(); i++) {
        if(!uniqueWords.contains(words[i])) {
            uniqueWords.append(words[i])
        }
    }
    return uniqueWords
}
```
## Sprawdzic czy słowo jest anagram.
```
function isAnagram(word1, word2) {
    word1 = word1.tolower()
    word2 = word2.tolower()
    word1 = sortString(word1)
    word2 = sortString(word2)
    if(word1 == word2) {
        return true
    }
    else {
        return false
    }
}

function sortString(string) {
    char[] chars = string.toCharArray()
    Arrays.sort(chars)
    return new String(chars)
}

```
