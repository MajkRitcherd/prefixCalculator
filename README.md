<p align="center">
  <img src="MKWhite.png" width=50% height=50% align="center">
</p>

# <center> Prefix Calculator </center>

This is **NOT** Graphical calculator, it's **Console App.**
- Can be used for educational purposes (Under Education configuration).
- Developed using C++ with third party library for JSON.

Freetime project I am currently working on.  

## How-to build

**Download** -  (Code -> Download ZIP) 

**Clone** - (go to directory, where you want it to be located, open cmd here
and type: `git clone https://github.com/MajkRitcherd/prefixCalculator.git` ). 

 Then run **GenerateProject.bat** file to generate VS solution.
 

## Future

- More mathematical operations ... **[✓]**
- Constants ... **[✓]**
- Number representations ... **[✓]**
- Save expressions, results ... **[Not fully implemented]**
- Currency ... **[✓]**
- Educational purposes ... **[Not fully implemented]**

# Documentation

### TABLE OF CONTENTS:
   - [Why Prefix Calculator](#why-prefix-calculator)
   - [Control characters](#control-characters)
   - [Allowed inputs](#allowed-inputs)
   - [Numbers](#numbers)
   		- [Decimal numbers](#decimal-numbers)
   		- [Binary numbers](#binary-numbers)
   		- [Hexadecimal numbers](#hexadecimal-numbers)
   		- [Roman numerals](#roman-numerals)
   		- [Fractions](#fractions)
   		- [Saved numbers](#saved-numbers)
   - [Operations](#operations)
   		- [Arithmetic](#1-arithmetic)
   		- [Algebra](#2-algebra)
   		- [Goniometric](#3-goniometric)
   		- [Currency](#4-currency)
   		- [Others](#5-others)

### **Why Prefix Calculator**

I was a bachelor (Computer Science) student at **University Palacký**. I quite like mathematics and when I heard about prefix notation, especially in no need of Parentheses in expressions, I had to make it.\
\
The goal at the start was to make calculator which would work with whole numbers and wanted to improve my programming skills. I chose C++, because I wanted to make it the harder way and I prefer to write code in this language. It's only Console Application for now, maybe I'll add GUI someday, and now it supports various representations of number (See [Numbers](#numbers)) and a lot of mathematical operations, such as Arithmetic operations, operations from Algebra, and few more... (See [Operations](#operations) for more info)\
\
It is **NOT** final version, some changes will be made...\
\
If you encounter some flaws or bugs, let me know here or at **misutak87@gmail.com**.

### **Control characters**

Every control character starts with '-' followed by one of these characters (c, h, i, io, s, ssr, u, q) 

- "**-c**" - Clears history of results
- "**-h**" - Shows history of results, history can hold up to 10 last results
- "**-i**" - Prints brief information table about control characters and numbers
- "**-io**" - Prints all available operations
- "**-s**" - Saves result into memory
- "**-ssr**" - Shows Memory table of all saved numbers with their position, example **'s1: 15'**, where 's1' is position in memory and '15' is the number
- "**-u**" - Updates JSON file with currencies
- "**-q**" - Quits the Calculator

### **Allowed inputs**

- Use only prefix notation, e.g. **'+ 2 2'** ("2 + 2" using infix notation),  
 **'pow 5 + 1 1'** (using infix: 5^(1 + 1) = 5^2)
- You have to start expression with number or operator, only 1 space between each character
- No parentheses needed, that's the beauty of prefix notation
- Use allowed numbers (See [Works with](#works-with)), you can combine them as you wish
- Also you can use saved number

### **Numbers**
- #### ***Decimal Numbers***
	- Can be both Positive or Negative
	- Nothing special here, keep reading...
	- e.g. -12, 0, 15, ...
	    
- #### ***Binary Numbers***
	- Can only be Positive
	- Use prefix ***0b***
	- e.g. 0b001, 0b10101, ...
	- [Binary number - Simple English Wikipedia, the free encyclopedia](https://simple.wikipedia.org/wiki/Binary_number) (Easier to understand)
	- [Binary number - Wikipedia](https://en.wikipedia.org/wiki/Binary_number)
	    
- #### ***Hexadecimal Numbers***
	- Can only be Positive
	- Use prefix ***0x***
	- Also don't forget to use ***Upper-case*** for letters
	- e.g. 0x08A, 0xFFD, ...
	- [Hexadecimal - Simple English Wikipedia, the free encyclopedia](https://simple.wikipedia.org/wiki/Hexadecimal) (Easier to understand)
	- [Hexadecimal - Wikipedia](https://en.wikipedia.org/wiki/Hexadecimal)
	    
- #### ***Roman Numerals***
	- You won't find 0 here and also Negative numbers
	- Use ***Upper-case*** for letters
	- e.g. IV, MCMLXXXIV
	- [Roman numerals - Simple English Wikipedia, the free encyclopedia](https://simple.wikipedia.org/wiki/Roman_numerals) (Easier to understand)
	- [Roman numerals - Wikipedia](https://en.wikipedia.org/wiki/Roman_numerals)
	    
- #### ***Fractions***
	- Can be either Positive or Negative
	- Numerator and Denominator can be only ***whole numbers***
	- Negative sign can be put wherever you want, but please, only one for each number
	- e.g. 4/5, -2/3

- #### ***Saved Numbers***
	- To save last result into the Calculator's memory, type '-s'.
	- To access arbitrary number from Calculator's memory, you need to know its position.\
	  Position you can find in Memory table, using '-ssr'.
	- Example: Let's say we have Memory Table like this: `s0: 5, s1:10`.
	- Then to access one of these numbers in expression, you type **'+ s0 7'**, the Calculator then replaces s0 with its stored value, in this case with number **5**, and removes it from Calculator's memory. After that it will compute the result. 
	

### **Operations**

Every operator has form: `operator - x (r), e`, where x = number of required operands, r = what operator does, e = example of use \
Operations are divided into subgroups in document for better orientation:

- #### ***1. Arithmetic***
	- **'+'** - 2 operands (Adds number1 and number2) e.g. `+ number1 number2`.
	- **'-'** - 2 operands (Subtracts number2 from number1), e.g. `- number1 number2`.
	- **'*'*** - 2 operands (Multiplies number1 with number2), e.g. ` number1 number2`.
	- **'/'** - 2 operands (Divides number1 by number2), e.g. `/ number1 number2`.

- #### ***2. Algebra***
	- **'pow'** - 2 operands (Returns num1 to the power of num2), e.g. `pow num1 num2`.
	- **'mod'** - 2 operands (Returns remainder after dividing num1 by num1), e.g. `mod num1 num2`.
	- **'abs'** - 1 operand (Returns absolute value of num1), e.g. `abs num1`.
	- **'sqrt'** - 1 operand (Returns square root of num1), e.g. `sqrt num1`.
	- **'cbrt'** - 1 operand (Returns cubic root of num1), e.g. `cbrt num1`.
	- **'fac'** - 1 operand (Multiplies all whole numbers from num1 down to 1), e.g. `fac num1`.
	- **'log'** - 1 operand (Computes decimal logarithm of num1), e.g. `log num1`.
	- **'ln'** - 1 operand (Computes natural logarithm of num1), e.g. `ln num1`.

- #### ***3. Goniometric***
	- **'sin'** - 1 operand (Returns sinus of num1), e.g. `sin num1`.
	- **'cos'** - 1 operand (Returns cosinus of num1), e.g. `cos num1`.
	- **'tan'** - 1 operand (Returns tangent of num1), e.g. `tan num1`.
	- **'cotan'** - 1 operand (Returns cotangent of num1), e.g. `cotan num1`.

- #### ***4. Currency***
	- **'cz-eu'** - 1 operand (Converts num1 from CZK to Euro), e.g. `cz-eu num1`.
	- **'cz-do'** - 1 operand (Converts num1 from CZK to USD), e.g. `cz-do num1`.
	- **'cz-po'** - 1 operand (Converts num1 from CZK to GBP), e.g. `cz-po num1`.
	- **'eu-cz'** - 1 operand (Converts num1 from Euro to CZK), e.g. `eu-cz num1`.
	- **'eu-do'** - 1 operand (Converts num1 from Euro to USD), e.g. `eu-do num1`.
	- **'eu-po'** - 1 operand (Converts num1 from Euro to GBP), e.g. `eu-po num1`.
	- **'do-cz'** - 1 operand (Converts num1 from USD to CZK), e.g. `do-cz num1`.
	- **'do-eu'** - 1 operand (Converts num1 from USD to Euro), e.g. `do-eu num1`.
	- **'do-po'** - 1 operand (Converts num1 from USD to GBP), e.g. `do-po num1`.
	- **'po-cz'** - 1 operand (Converts num1 from GBP to CZK), e.g. `po-cz num1`.
	- **'po-eu'** - 1 operand (Converts num1 from GBP to Euro), e.g. `po-eu num1`.
	- **'po-do'** - 1 operand (Converts num1 from GBP to USD), e.g. `po-do num1`.

- #### ***5. Others***
	- **'sum'** - Arbitrary count of operands (Returns their summation), e.g. `sum num1 num2 num3 ...`.
	- **'prod'** - Arbitrary count of operands (Return their product), e.g. `prod num1 num2 num3 ...`.
