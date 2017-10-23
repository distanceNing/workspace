##### 利用三层架构实现简单登陆功能的流程:

自顶向下：

    用户表达层： usl  收集到用户的登录请求，向bll发送登录请求，得到处理结果后，给予用户展示

    业务逻辑层： bll  接受到用户请求，进行处理，并返回处理结果

    数据访问层： dal  连接数据库，访问数据库，向bll传递数据

module：用于数据传递的数据结构。

sql_helper:提供了连接数据库，数据库查询的方法。

net_helper:简单封装了socket。用于usl和bll之间的通信。