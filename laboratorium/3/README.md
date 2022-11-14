# Pseudokody

## [Działania z kolejką](labaratorium/3/Działania z kolejką.c)

### insert(item, struct end)
```
allocate new_node
    declare struct last pointer and set to end pointer
    set new_node value to item
    set new_node next to null
    if(end pointer == null)
      set end pointer to new_node
      end
    while(last next != null) do
      set last to last next
    set last next to new_node
    end
```

### removeItem(pos, struct head)
```
    declare struct temp pointer and set to head pointer and prev pointer
    if(temp != null and pos == 0)
      set head pointer to temp next
      free temp
      end
    while(temp != null and pos--) do
      set prev to temp
      set temp to temp next
    if(temp == null)
      end
    set prev next to temp next
    free temp
    end
```

### printList(struct head pointer)
```
while(head != null) do
      print head value
      set head to head next
end
```

# Działania z listą cykliczną

### clearVisits(structure head)
```
set structure temp pointer to head pointer
  
    while(temp != null and temp->visited == 1) do
      set visited member in temp to 0
      set temp to the next node
end
```

### find(value, structure head)
```
set current pointer to head
    while(current != null and current->visited != 1) do
      set visited member in current to 1
      if(value member in current == value)
        clear all visits in nodes
        return 1
      set current to the next node
  clear all visits in nodes
end
```

### locate(value, structure head)
```
  while(head != null and visited member in head != 1) do
      set visited member in head to 1
      if(value member in head == value)
        clear all visits in nodes
        return head
      set head to the next node
    clear all visits in nodes
   end
```

### retrieve(pointer, structure head)
```
    clear all visits in nodes
  
    while(head != null and visited member in head != 1) do
      set visited member in head to 1
      if(head == pointer)
        clear all visits in nodes
        return value member in head
      set head to the next node
    clear all visits in nodes
    end
```

### insert(position pointer, value, next pointer)
```
 if(position pointer == null)
      print "the previous node cannot be NULL"
      end
    allocate new structure called new_node
    set value member in new_node to value
    set new_node next node pointer to position pointer next node pointer
    set position pointer next node pointer to new_node
    set new_node previous node pointer to position pointer
    if(new_node next node pointer != null)
      set new_node next node previous node pointer to new_node
    elseif(new_node next node pointer == null)
      set new_node next node pointer to next pointer
  end
```

### printList(structure head)
```
 set struct temp pointer to head pointer
    while(temp!=null and visited member in temp != 1)
      print value member in temp
      set visited member in temp to 1
      set temp to next node
    clear all visits in nodes
    end
```

### removeItem(struct head, pointer)
```
set struct temp pointer to head pointer and prev pointer
    clear all visits in nodes
    if(temp != null and temp == pointer)
      set head pointer to next member in temp
      free temp
      end
    while(temp != null and temp != pointer and visited member in temp != 1) do
      set visited member in temp to 1
      set prev to temp
      set temp to next node
    if(temp == null)
      clear all visits in nodes
      end
    set next member in prev to to next member in temp
    clear all visits in nodes
    free temp
```

### findMax(structure head)
```
declare struct max pointer and temp pointer
    set temp to max to head pointer
    clear all visits in nodes
    while(temp != null and visited member in temp != 1) do
      if(value member in temp > value member in max)
        set max to temp
      set visited member in temp to 1
      set temp to next member in temp
    clear all visits in nodes
    return max value
```

### findMin(struct head)
```
declare struct min pointer and temp pointer
    set temp to min to head pointer
    clear all visits in nodes
    while(temp != null and temp visited != 1) do
      if(temp value < min value)
        set min to temp
      set temp visited to 1
      set temp to next node
    clear all visits in nodes
    return min value
```

### size(struct head)
```
declare struct current pointer and set to head
  declare and set i to 0
  while(current != null and current visited != 1) do
    i++
    set current visited to 1
    set current to next node
  clear all visits in nodes
  return i
```

### isEmpty(struct head)
```
if(head == null)
      return 1
    return 0
```

### next(item pointer, struct head)
```
clear all visits in nodes
    while(head != null and head visited != 1) do
      if(head == item)
        clear all visits in nodes
        return head next value
      set head to head next
    clear all visits in nodes
    end
```

### prev(item pointer, struct head pointer)
```
clear all visits in nodes
    while(head != null and head visited != 1) do
      if(head == item)
        clear all visits in nodes
        return head prev value
    end
```

### makeNull(struct head pointer)
```
declare struct temp pointer
    while(head != null) do
      set temp to head
      set head to head next
      free temp
  end
```

## Działania z listą dwóchkierunkową niesortowaną
### find(value, struct head pointer)
```
declare and set current pointer to head
    while(current != null) do
      if(current value == value)
        return 1
      set current to current next
    end
```

### locate(value, struct head pointer)
```
while(head != null) do
      if(head value == value)
        return head
      set head to head next
    end
```

### retrieve(pointer, struct head pointer)
```
while(head != null) do
      if(head == pointer)
        return head value
      set head to head next
    end
```

### insert(struct head pointer, item)
```
if(head == null)
      end
    allocate new_node
    set new_node value to item
    set new_node next to head next
    set head next to new_node
    set new_node prev to head
    if(new_node prev != null)
      set new_node next prev to new_node
    end
```

### printList(struct head pointer)
```
while(head != null) do
      print head value
      set head to next node
    end
```

### removeItem(struct head, pointer)
```
declare and set temp pointer to head and prev pointer
    if(temp != null and temp == pointer)
      set head pointer to temp next
      free temp
      end
    while(temp != null and temp != pointer) do
      set prev to temp
      set temp to temp next
    if(temp == null)
      end
    set prev next to temp next
    free temp
    end
```

### findMax(struct head)
```
declare max pointer and temp pointer
    set temp to max to head pointer
    while(temp != null) do
      if(temp value > max value)
        set max to temp
      set temp to temp next
    return max value
```

### findMin(struct head)
```
declare struct min pointer and temp pointer
    set temp to min to head pointer
    while(temp != null) do
      if(temp value < min value)
        set min to temp
      set temp to temp next
    return min value
```

### size(struct head pointer)
```
declare and set current pointer to head
    declare and set i to 0
    while(current != null) do
      i++
      set current to current next
    return i
```

### isEmpty(struct head pointer)
```
if(head == null)
      return 1
    return 0
```

### next(item pointer, struct head pointer)
```
while(head != null) do
      if(head == null)
        return head next value
      set head to head next
    end
```

### prev(item pointer, struct head pointer)
```
while(head != null) do
      if(head == item)
        return head prev value
      set head to head next
    end
```

### makeNull(struct head pointer)
```
declare struct temp pointer
    while(head != null) do
      set temp to head
      set head to head next
      free temp
    end
```
