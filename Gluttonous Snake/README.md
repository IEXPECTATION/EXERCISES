首先先原谅我蹩脚的英文，因为所有的注释均使用英文。道歉的理由是，一个极烂的注释,不如没有注释。

接下来就开始我的说明吧。

这是一个极其简陋的贪吃蛇源代码，我利用一个名为info.h的头文件定义双手都能说出来的宏和函数声明，只有少数宏和函数被单独声明。所以观看过info.h这个头文件便能大致了解整个代码的结构。
其中，我在Gluttonous Snake.c里定义了主函数（main函数），但是它只调用了printmap函数打印游戏的地图和printsnake函数控制蛇身和其他一些判断等。printsnake是真正在运行的函数，它包括打印蛇头和蛇身，移动蛇头和蛇身，判断蛇是否还活着，生成贪吃蛇吃的食物，甚至包含了接收用户的输入。但不幸的是，使用的_kbhit似乎有延迟。
我将在头文件里被声明的函数都使用了一个单独的实现进行定义，但是有几个函数被我直接定义在实现里，他们都是用作一些判断的函数。
现在说一说游戏吧，为了还原原汁原味的贪吃蛇，使蛇能自己移动。我使用了单链表，甚至在蛇的结构体中声明了一个dire（direction）的变量，它的意思是标识蛇头移动的方向，但是这个特殊的待遇也只有蛇头拥有，所有的蛇身均为'\0'。这样我可利用蛇头（头节点）控制蛇身的移动。利用一个指针指向了蛇尾，让我每次都能正确的消除蛇尾，但是因为蛇尾的问题，这样我很难对蛇吃到食物时蛇身加长做出正确的处理。所以我舍友给我一个提议，那就是当蛇吃到食物时，蛇头向前前进一格来解决蛇尾的问题。但是这样做的结果就是当食物刷新在墙边上时，你不能让头与墙垂直去吃食物，如果这么做的结果只有一个，那就是game over。至于如何修改对蛇身的加长，就留给以后再去思考了。
上文说到了不能让头与墙垂直去吃食物，那接下来来说说游戏的整体。判断蛇是否还活着不只是判断蛇头是否和墙重叠，还有就是蛇头是否和蛇身重叠。又因为时单链表，所以当蛇身越来越长的时候,遍历整个蛇的时候就会越来越慢，这就会造成卡顿，毕竟这只是个简陋的c语言代码。但在我测试的时候，吃完食物的时候也会有卡顿，因为在每次移动或者吃到食物，都会有大量的判断。比如说，每走一步都回判断蛇是否还活着，比如生成食物时，要避免食物生成在墙上或者在蛇的身体里面。这些都要遍历整个蛇来判断。
最后呢，这是一个简单又简陋的平常练习，有很多错误也是不可避免的，我希望在日我能通过这种练习来提升自己的实力。毕竟”古人云：千里之行，始于足下“嘛！

代码的测试平台:Windows         测试软件：visual studio 2017



