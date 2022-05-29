insert()	它将新元素插入到迭代器指向的位置之前。
push_back()	它在容器的末尾添加了一个新元素。
push_front()	它在前面增加了一个新元素。
pop_back()	删除最后一个元素。
pop_front()	删除第一个元素。
empty()	它检查列表是否为空。
size()	它查找列表中存在的元素数。
max_size()	它找到列表的最大大小。
front()	它返回列表的第一个元素。
back()	它返回列表的最后一个元素。
swap()	当两个列表的类型相同时，它将交换两个列表。
reverse()	它反转了列表的元素。
sort()	它以递增的顺序对列表中的元素进行排序。
merge()	它合并两个排序的列表。
splice()	它将新列表插入到调用列表中。
unique()	它从列表中删除所有重复的元素。
resize()	它更改列表容器的大小。
assign()	它将一个新元素分配给列表容器。
emplace()	它将在指定位置插入一个新元素。
emplace_back()	它将在容器的末尾插入一个新元素。
emplace_front()	它将在列表的开头插入一个新元素。

list<int>::iterator it = begin(); it != rend() 遍历
list<int>::reverse_iterator rit = rbegin(); rit != rend() 倒序遍历