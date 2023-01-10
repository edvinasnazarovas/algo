```
function longestWord(string) {
  n = length(string)
  curr_len = 0
  max_len = 0
  longestString
  
  for(i = 0; i < n; i++)
    if(string[i] != ' '
      curr_len++
    else
      if(curr_len > max_len)
        max_len = curr_len
        longestString = string[i]
      curr_len = 0
   return longestString
}

deleteWord(string, key) {
  i, j = 0
  k = 0
  count = 0
  for(i = 0; string[i] != ' '; i++)
    if(string[i] == ' ')
      string1[k][j] = '\0'
      k++
      j = 0
    else
      string1[k][j] = string[i]
      j++
   string1[k][j] = '\0'
   for(i = 0; i < k + 1; i++)
    if(strcmp(string1[i], key) == 0
      for(j = 0; j < k + 1; j++)
        strcpy(string1[j], string1[j + 1])
      k--
}

