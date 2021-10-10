## 代码内容阐述

以上代码实现了对二叉树的初始化构造，并根据书中的例程对二叉树的一些功能实现。

查找功能：通过与父节点比大小来进一步确定位置

寻找最小元：即查找最左元

寻找最大元：即查找最右元

插入操作：较为复杂首先创建并返回一个单节点树，然后根据其大小查找其应处的位置并插入，若不在查找条件中则说明X已经存在于树中

删除操作：分为两种情况，第一种情况只有一个儿子，第二种情况有两个儿子分情况进行删除