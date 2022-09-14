## 定位
begin()                  返回指向 map 头部的迭代器
rbegin()                返回一个指向map尾部的逆向迭代器
rend()                   返回一个指向map头部的逆向迭代器
end()                     返回指向 map 末尾的迭代器

## 增
    insert()                  插入元素

## 删
    erase()                   删除一个元素
    clear(）                 删除所有元素

## 查
    count()                  返回指定元素出现的次数
    empty()                 如果 map 为空则返回 true
    find()                     查找一个元素
    

## 其它
    get_allocator()      返回map的配置器
    key_comp()          返回比较元素key的函数
    lower_bound()     返回键值>=给定元素的第一个位置
    max_size()            返回可以容纳的最大元素个数
    size()                    返回map中元素的个数
    swap()                 交换两个map
    upper_bound()    返回键值>给定元素的第一个位置
    equal_range()        返回特殊条目的迭代器对
    value_comp()       返回比较元素value的函数
