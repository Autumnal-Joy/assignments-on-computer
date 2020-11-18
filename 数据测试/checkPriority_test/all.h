// 操作数栈的节点
typedef struct _num_node {
    // 操作数
    double num;
    // 下一个节点
    _num_node* nextNode;
} NumNode;

// 操作符栈的节点
typedef struct _ope_node {
    // 操作符
    char ope;
    // 下一个节点
    _ope_node* nextNode;
} OpeNode;

/*
    @param {char*} pstr: 获取用户输入的以'='结尾的字符串, 保存于此地址, 最多保存99个有效字符(包含空白字符)
*/
void getUserInput(char* pstr);

/*
    @param {char*} pstr: 用户输入的表达式字符串地址
    @return {double}: 计算结果

    需要一个操作数栈和一个操作符栈
    循环读取字符串下一个操作数或操作符
        若是操作数, 就直接压入操作数的栈
        若是操作符, 则开始讨论
            若此操作符是左括号, 则直接压入操作符的栈
            若此操作符是右括号, 则不断弹出操作符, 直到弹出左括号为止
                若是单目的操作符, 则弹出一个操作数上,作用在操作数上并压入操作数的栈
                若是双目的操作符, 则弹出两个操作数, 按照"先弹出 操作符 后弹出"的顺序计算结果并压回操作数的栈
            若此操作符可用于计算
                若栈顶操作符的优先级不小于此操作符, 则不断弹出操作符, 直到条件不成立
                    其中, 弹出的单目或双目操作符以同样规则从操作数的栈中取出数, 计算出结果并压回操作数的栈
                若操作符是等号, 说明表达式读取到了尾部, 此时退出循环, 否则把此操作符压入操作符的栈
    此时操作数的栈内有且仅有一个操作数
    释放栈的内存后, 将此操作数返回
*/
double calculate(char* pstr);

/*
    @param {char*} pstr: 用户输入的表达式字符串地址

    将取反符号'-'改变为'~', 减号'-'不变
*/
void preProcess(char* pstr);

/*
    @param {char*} pstr: 表达式字符串地址
    @param {char*} isNum: 传入的char类型变量的地址, 用于反馈给调用者返回值是操作数还是操作符, 修改指向位置的char类型变量的值为0或1
    @return {int} 返回下一个操作数或操作符的对应字符

    定义静态变量loc, 记录读取的起始位置, 初始为0
    从loc位置开始读取下一个操作数或操作符, 修改loc的值和isNum指针指向的char类型变量的值后, 将操作数或操作符的类别返回
    特殊的操作符, 用对应的单字符来创建节点
    当读到'\0'时, loc重新置零, *isNum置零, 返回'='
*/
char nextOneIsNum(char* pstr, char* nextOpe, double* nextNum);

/*
    优先级0:
    '(': 左括号分组符,
    '=': 表达式末尾等号,
    优先级1:
    '+': 双目加法运算符,
    '-': 双目减法运算符,
    优先级2:
    '*': 双目乘法运算符,
    '/': 双目除法运算符,
    '~': 单目取反运算符,
    优先级3:
    '^': 双目乘方运算符,
    优先级4:
    's': 单目正弦运算符,
    'c': 单目余弦运算符,
    't': 单目正切运算符,
    'o': 单目余切运算符,
    'g': 单目常用对数运算符,
    'n': 单目自然对数运算符,

    @param {char} ope: 操作符ope
    @return {int}: 操作符的优先级
*/
int checkPriority(char ope);

/*
    @param {char*} p: 以一个操作符开始的字符串的地址
    @return {char}: 操作符对应的字符

    多字符的操作符转换为对应单字符后返回
        'sin': 's'
        'cos': 'c'
        'tan': 't'
        'cot': 'o'
        'lg': 'g'
        'ln': 'n'
*/
char getType(char* p);

/*
    @param {char} ope: 操作符
    @param {NumNode*} numStack: 操作数所在的栈

    若是单目的操作符, 则从操作数的栈中弹出一个操作数, 将操作符作用在操作数上并压入操作数的栈
    若是双目的操作符, 则弹出两个操作数, 按照"先弹出 操作符 后弹出"的顺序计算结果并压回操作数的栈
*/
double getValue(char ope, NumNode* numStack);

/*
    @return {NumNode*}: 返回操作数栈的表头
*/
NumNode* createNumStack(void);

/*
    @return {OpeNode*}: 返回操作符栈的表头
*/
OpeNode* createOpeStack(void);

/*
    @param {double} num: 创建一个操作数节点来保存操作数num
    @return {NumNode*}: 返回创建的操作数节点地址
*/
NumNode* createNumNode(double num);

/*
    @param {char} ope: 创建一个操作符节点来保存操作符ope
    @return {OpeNode*}: 返回创建的操作符节点地址
*/
OpeNode* createOpeNode(char ope);

/*
    @param {OpeNode*} stack: 受到操作的操作符栈
    @param {char} ope: 待压入栈的操作符
*/
void pushOpe(OpeNode* stack, char ope);

/*
    @param {NumNode*} stack: 收到操作的操作数栈
    @param {double} num: 待压入栈的操作数
*/
void pushNum(NumNode* stack, double num);

/*
    @param {NumNode*} stack: 受到操作的操作数栈
    @return {char}: 栈是否空, 返回0或1
*/
char isNumStackEmpty(NumNode* stack);

/*
    @param {NumNode*} stack: 受到操作的操作符栈
    @return {char}: 栈是否空, 返回0或1
*/
char isOpeStackEmpty(OpeNode* stack);

/*
    @param {NumNode*} stack: 受到操作的操作数栈
    @return {double}: 从操作数栈中弹出的操作数, 若栈已空则返回0
*/
double popNum(NumNode* stack);

/*
    @param {OpeNode*} stack: 受到操作的操作符栈
    @return {char}: 从操作符栈中弹出的操作符, 若栈已空则返回0
*/
char popOpe(OpeNode* stack);

/*
    @param {NumNode*} stack: 受到操作的操作数栈
    @return {double}: 操作数栈顶元素, 若栈已空则返回0
*/
double topNum(NumNode* stack);

/*
    @param {OpeNode*} stack: 受到操作的操作符栈
    @return {char}: 操作符栈顶元素, 若栈已空则返回0
*/
char topOpe(OpeNode* stack);

/*
    @param {NumNode*} stack: 受到操作的操作数栈
*/
void deleteNumStack(NumNode* stack);

/*
    @param {OpeNode*} stack: 受到操作的操作符栈
*/
void deleteOpeStack(OpeNode* stack);

/*
    括号不匹配时调用以终止程序
*/
void bracketsNotMatched(void);

/*
    除以0时调用以终止程序
*/
void divideByZeroError(void);

/*
    表达式不符合规则时调用以终止程序
*/
void illegalExpression(void);

/*
    变量不在函数定义域内时调用以终止程序
*/
void valueRangeError(void);

/*
    操作符错误时调用以终止程序
*/
void operatorNameError(void);

