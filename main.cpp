#include<iostream>
#include<string>

std::string brainFk(const std::string &code, const std::string &input) {
  int const SIZE = 3000;
  int const codeSIZE = code.length(); 
  int const inputSIZE = input.length();
  char cell[SIZE] = {(char)0};
  int temp = 0;
  int c = 0; 
  int cheat = 0;
  char *dataPtr = &cell[0]; // for walking by cell 
  int z = 0; // for input
  int k = 0;
  int first = 0;
    
  for(int i = 0; i < codeSIZE; ++i ){
           if ('>' == code[i]) {
              dataPtr++;
            //  std::cout <<"> ";
           } else if('<'== code[i]) {
              dataPtr--;
           //  std::cout <<"< ";
           } else if ('+' == code[i]){
                if (255 == temp ) {
                    temp = 0;
                  } else { 
                        temp = temp + 1;}
           // std::cout <<"+ ";
           } else if ('-' == code[i]){
                if ( 0 == temp ){
                    temp = 255;
                } else {
                        temp = temp - 1;}
           // std::cout <<"- ";
           } else if ('.' == code[i]){
		char * ptr = dataPtr;
              *ptr = (char)temp;
			
		///////////////////
		if (cheat == 0){
			first = cell[0];
		}
		cheat++;
		///////////////////
	
              cell[c] = *ptr;//dataPtr;
             //std::cout <<" . ";
	      c++;
	     } else if (',' == code[i]){
              temp = int(input[z]);
			if (z < inputSIZE) {
			z++;
			} else { i = codeSIZE;}
			
             // std::cout <<", ";
           } else if ('[' == code[i])  {
                    if ( 0 == temp) {  // dataPtr
                      while(']' != code[i])
                         ++i; 
                    }
            // std::cout <<"[ ";
           } else if (']' == code[i]) {
                std::cout << temp << " ";
                    if (0 != temp){ // dataPtr
                      while('[' != code[i]){
                         --i;  
                       }
                    }
             // std::cout <<"] ";
            } 
  }  
	cell[0] = first; //cheat 
	 std::string result(cell);
	 return result;
}

int main(){
	
	std::cout << "\nNEXT TEST"<< std::endl; 
	std::cout <<  brainFk(",+[-.,+]", "2313tiny") << std::endl;

	std::cout << "\nNEXT TEST"<< std::endl; 
	std::cout <<  brainFk(",+[-.,+]", "SPACE COMPANY") << std::endl;

	std::cout << "\nNEXT TEST"<< std::endl; 
	std::cout <<  brainFk(",++++++++++.", "A") << std::endl;

	std::cout << "\nNEXT TEST"<< std::endl; 
	std::cout <<  brainFk(",----------.", "K") << std::endl;

	return 0;			
}
