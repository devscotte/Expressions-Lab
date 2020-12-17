#include "ExpressionManager.h"
#include <sstream>
#include <vector>



bool ExpressionManager::isBalanced(string expression){
    cout << "isBalanced" << expression << endl;
    
    stack<char> myStack;
    char myChar;
    bool myBool = true;
    
    
    for (int i = 0; i < expression.length(); ++i){
    	if(expression.at(i) == '(' || expression.at(i) == '{' || expression.at(i) == '['){
    		myStack.push(expression.at(i));
    		continue;
    	}
    	else if(expression.at(i) == ')'){
    		if(myStack.size() == 0){
    			myBool = false;
    		}
    		else{
    			myChar = myStack.top();
    			myStack.pop();
    			if(myChar == '{' || myChar == '['){
    				myBool = false;
    				break;
    			}
    			
    		}
    	}
    	else if(expression.at(i) == '}'){
    		if(myStack.size() == 0){
    			myBool = false;
    		}
    		else{
    			myChar = myStack.top();
    			myStack.pop();
    			if(myChar == '(' || myChar == '['){
    				myBool = false;
    				break;
    			}
    		}
    	}
    	else if(expression.at(i) == ']'){
    		if(myStack.size() == 0){
    			myBool = false;
    		}
    		else{
    			myChar = myStack.top();
    			myStack.pop();
    			if(myChar == '(' || myChar == '{'){
    				myBool = false;
    				break;
    			}
    		}
    	}
    }
    if(myStack.size() != 0){
    	myBool = false;
    }
    
    
    return myBool;
}

	/**
	* Converts a postfix expression into an infix expression
	* and returns the infix expression.
	*
	* - The given postfix expression will have a space between every number or operator.
	* - The returned infix expression must have a space between every number or operator.
	* - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if postfixExpression is not a valid postfix expression.
	* otherwise, return the correct infix expression as a string.
	*/
	string ExpressionManager::postfixToInfix(string postfixExpression){
	    cout << "postfixToInfix " << postfixExpression << endl;
	    
	    stack<string> myPostStack;
	    string myPostString;
	    string myPostStringTwo;
	    string myPostOp;
	    vector<string> testVect;
	    string invalidString = "invalid";

	    istringstream iss(postfixExpression);
	    
	    do { 
			string input; 
        	iss >> input;
        	testVect.push_back(input);
        	
  
        	
    	} while (iss);
    	
    	if(testVect.at(0).find('+') != string::npos || testVect.at(0).find('-') != string::npos || testVect.at(0).find('*') != string::npos || 
    		testVect.at(0).find('/') != string::npos || testVect.at(0).find('%') != string::npos){
    			return invalidString;
    	}
    	
    	if(testVect.at(1).find('+') != string::npos || testVect.at(1).find('-') != string::npos || testVect.at(1).find('*') != string::npos || 
    		testVect.at(1).find('/') != string::npos || testVect.at(1).find('%') != string::npos){
    			return invalidString;
    	}
    	
    	if(postfixExpression.find('+') == string::npos && postfixExpression.find('-') == string::npos && postfixExpression.find('*') == string::npos && 
    		postfixExpression.find('/') == string::npos && postfixExpression.find('%') == string::npos){
    			cout << "String contains no operator" << endl;
    			return invalidString;
    	}
    	
    	
    	for(int i = 0; i < testVect.size() - 1; ++i){
    		if(testVect.at(i).find('f') != string::npos || testVect.at(i).find('a') != string::npos || testVect.at(i).find('@') != string::npos){
    			return invalidString;
    		}
    		
    		if(testVect.at(i).find('.') != string::npos){
    			return invalidString;
    		}
    		
    		if(testVect.at(i).find('+') == string::npos && testVect.at(i).find('-') == string::npos && testVect.at(i).find('*') == string::npos && 
    		testVect.at(i).find('/') == string::npos && testVect.at(i).find('%') == string::npos){
    			cout << "Stacking Operands" << endl;
    			myPostStack.push(testVect.at(i));
    		}
    		else{
    			cout << "Combining terms" << endl;
	    		myPostString = myPostStack.top();
	    		cout << "Values set as strings" << endl;
	    		myPostStack.pop();
	    		cout << "Value popped from stack" << endl;
	    		if(myPostStack.size() == 0){
	    			return invalidString;
	    		}
	    		else{
	    		myPostStringTwo	= myPostStack.top();
	    		cout << "Second value checked" << endl;
	    		myPostStack.pop();
	    		cout << "Second value popped" << endl;
	    		myPostStack.push("( " + myPostStringTwo + " " + testVect.at(i) + " " + myPostString + " )");
	    		cout << myPostStack.top() << endl;
	    		}
    		}
    	} 
	    cout << "Postfix to Infix complete" << endl;
	    
	    
	    
        return myPostStack.top();
	}

	/*
	* Evaluates a postfix expression returns the result as a string
	*
	* - The given postfix expression will have a space between every number or operator.
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if postfixExpression is not a valid postfix Expression
	* otherwise, return the correct evaluation as a string
	*/
	string ExpressionManager::postfixEvaluate(string postfixExpression){
		stack<int> postfixSolve;
		int myopChange;
		int myopFirst;
		int myopSecond;
		int myopResult;
		int convertInt;
		string convertString;
		vector<string> numVect;
		
		stringstream iss(postfixExpression);
		
		cout << "postfixEvaluate " << postfixExpression << endl;
	    
	    do { 
			string input; 
        	iss >> input;
        	numVect.push_back(input);
        	
  
        	
    	} while (iss); 
    	
    	if(numVect.at(0).find('+') != string::npos || numVect.at(0).find('-') != string::npos || numVect.at(0).find('*') != string::npos || 
    		numVect.at(0).find('/') != string::npos || numVect.at(0).find('%') != string::npos){
    			convertString = "invalid";
    			return convertString;
    	}
    	
    	if(numVect.at(1).find('+') != string::npos || numVect.at(1).find('-') != string::npos || numVect.at(1).find('*') != string::npos || 
    		numVect.at(1).find('/') != string::npos || numVect.at(1).find('%') != string::npos){
    			convertString = "invalid";
    			return convertString;
    	}
    	
    	if(isBalanced(postfixExpression) != true){
    		convertString = "invalid";
    		return convertString;
    	}
    	
    	
    	
    	for(int i = 0; i < numVect.size() - 1; ++i){
    		
    		if(numVect.at(i).find('.') != string::npos){
    			convertString = "invalid";
    			break;
    		}
    		
    		if(numVect.at(i).find('$') != string::npos){
    			convertString = "invalid";
    			break;
    		}
    		
    		if(numVect.at(i).find('+') == string::npos && numVect.at(i).find('-') == string::npos && numVect.at(i).find('*') == string::npos && 
    		numVect.at(i).find('/') == string::npos && numVect.at(i).find('%') == string::npos){
    			cout << "Stacking Operands" << endl;
    			myopChange = stoi(numVect.at(i));
    			postfixSolve.push(myopChange);
    		}
    		else{
    			cout << "Combining terms" << endl;
	    		myopSecond = postfixSolve.top();
	    		cout << "First value set" << endl;
	    		postfixSolve.pop();
	    		cout << "Value popped from stack" << endl;
	    		myopFirst = postfixSolve.top();
	    		cout << "Second value set" << endl;
	    		postfixSolve.pop();
	    		cout << "Second value popped" << endl;
	    		if(numVect.at(i).find('+') != string::npos){
	    			cout << "Adding terms" << endl;
	    			myopResult = myopFirst + myopSecond;
	    			cout << myopResult << endl;
	    			postfixSolve.push(myopResult);
	    		}
	    		else if(numVect.at(i).find('-') != string::npos){
	    			cout << "Subtracting terms" << endl;
	    			myopResult = myopFirst - myopSecond;
	    			cout << myopResult << endl;
	    			postfixSolve.push(myopResult);
	    		}
	    		else if(numVect.at(i).find('*') != string::npos){
	    			cout << "Multiplying terms" << endl;
	    			myopResult = myopFirst * myopSecond;
	    			cout << myopResult << endl;
	    			postfixSolve.push(myopResult);
	    		}
	    		else if(numVect.at(i).find('/') != string::npos){
	    			cout << "Dividing terms" << endl;
	    			if(myopSecond == 0){
	    				cout << "Can't divide by 0" << endl;
	    				convertString = "invalid";
	    				return convertString;
	    			}
	    			else{myopResult = myopFirst / myopSecond;
	    			cout << myopResult << endl;
	    			postfixSolve.push(myopResult);
	    			}
	    		}
	    		else if(numVect.at(i).find('%') != string::npos){
	    			cout << "Finding the remainder from terms" << endl;
	    			myopResult = myopFirst % myopSecond;
	    			cout << myopResult << endl;
	    			postfixSolve.push(myopResult);
	    		}
	    	
    		}
    	} 
		convertInt = postfixSolve.top();
		convertString = to_string(convertInt);
	    
	    
	    return convertString;
	}

	/*
	* Converts an infix expression into a postfix expression
	* and returns the postfix expression
	*
	* - The given infix expression will have a space between every number or operator.
	* - The returned postfix expression must have a space between every number or operator.
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if infixExpression is not a valid infix expression.
	* otherwise, return the correct postfix expression as a string.
	*/
	
	
int CheckPrecedence(string x){
	int addminPrec = 1;
	int multidivPrec = 2;
	int remPrec = 3;
	int xComp = 0;
	
	if(x.find('+') != string::npos || x.find('-') != string::npos){
		xComp = addminPrec;
	}
	else if(x.find('*') != string::npos || x.find('/') != string::npos){
		xComp = multidivPrec;
	}
	else if(x.find('%') != string::npos){
		xComp = remPrec;
	}
	
	
	return xComp;
}
	
	
	
	
	string ExpressionManager::infixToPostfix(string infixExpression){
		stack<string> myInStack;
	    string myInString;
	    string postfixString;
	    vector<string> inVect;
		stringstream iss(infixExpression);
		
	    cout << "infixToPostfix " << infixExpression << endl;
	    
	    do { 
			string input; 
        	iss >> input;
        	inVect.push_back(input);
        	
  
        	
    	} while (iss); 
    	
    	if(inVect.at(0).find('+') != string::npos || inVect.at(0).find('-') != string::npos || inVect.at(0).find('*') != string::npos || 
    		inVect.at(0).find('/') != string::npos || inVect.at(0).find('%') != string::npos){
    			postfixString = "invalid";
    			return postfixString;
    	}
    	
    	
    	if(isBalanced(infixExpression) != true){
    		postfixString = "invalid";
    		return postfixString;
    	}
    	
    	for(int i = 0; i < inVect.size() - 1; ++i){
    		
    		if(inVect.at(i).find('.') != string::npos){
    			postfixString = "invalid";
    			return postfixString;
    		}
    		
    		if(inVect.at(i).find('$') != string::npos || inVect.at(i).find('@') != string::npos || inVect.at(i).find('a') != string::npos){
    			postfixString = "invalid";
    			return postfixString;
    		}
    		
    		if(inVect.at(i).find('(') != string::npos){
    			cout << "Found first parenthese" << endl;
    			myInStack.push(inVect.at(i));
    		}
    		else if(inVect.at(i).find(')') != string::npos){
    			cout << "Found second parenthese" << endl;
    			while(myInStack.size() != 0 && myInStack.top().find('(') == string::npos){
    				myInString = myInStack.top();
    				myInStack.pop();
    				postfixString = postfixString + " " + myInString;
    				
    			}
    			if(myInStack.top().find('(') != string::npos){
    				myInString = myInStack.top();
    				myInStack.pop();
    			}
    		}
    		else if(inVect.at(i).find('+') == string::npos && inVect.at(i).find('-') == string::npos && inVect.at(i).find('*') == string::npos && 
    		inVect.at(i).find('/') == string::npos && inVect.at(i).find('%') == string::npos){
    			if(postfixString.length() == 0){
    				cout << "Found operand" << endl;
    				postfixString = inVect.at(i);
    			}
    			else{
    				cout << "Found operand" << endl;
    				postfixString = postfixString + " " + inVect.at(i);
    			}
    		}
    		else{
    			cout << "Found operator" << endl;
    			if(myInStack.size() == 0){
    				myInStack.push(inVect.at(i));
    			}
    			else if(myInStack.size() != 0){
    				cout << "Comparing stack with operator" << endl;
    				while(myInStack.size() != 0 && CheckPrecedence(inVect.at(i)) <= CheckPrecedence(myInStack.top())){
    					myInString = myInStack.top();
    					myInStack.pop();
    					postfixString = postfixString + " " + myInString;
    				}
    				myInStack.push(inVect.at(i));
    			}
    			
    		}
    		
    	}
    	while(myInStack.size() != 0){
    		myInString = myInStack.top();
    		myInStack.pop();
    		postfixString = postfixString + " " + myInString;
    	}
	    cout << postfixString << endl;
	    
	    return postfixString;
	}
