#include "List.h"

//Declaration
Recipe::Recipe(){

}
Recipe::Recipe(std::string name, int cTime, int pTime){
  recipeName = name;
  cookingTime = cTime;
  preparationTime = pTime;
}

//Setters
void Recipe::addIngredient(std::string item){
  ingredient.push_back(item);
}

void Recipe::addIngredientAmount(std::string amount){
  ingredientAmount.push_back(amount);
}

void Recipe::addInstruction(std::string instr){
  instructions.push_back(instr);
}
void Recipe::setRecipeName(std::string name){
  recipeName = name;
}

void Recipe::setCookingTime(int cTime){
  cookingTime = cTime;
}

void Recipe::setPreparationTime(int pTime){
  preparationTime = pTime;
}

void Recipe::inputInstructions(){
  std::string input;
  std::cout << "Enter instructions.\n";
  std::cout << "When finished, type exit.\n";
  while(true){
    std::getline(std::cin, input);
    if (input == "exit"){
      break;
    }
    while(true){
      if (input != ""){
        break;
      }
      std::cout << "Enter an intstruction\n";
    }
    instructions.push_back(input);
    input.clear();
  }
}
//Getters
std::string Recipe::getRecipeName(){
    return recipeName;
}

int Recipe::getCookingTime(){
  return cookingTime;
}

int Recipe::getPreparationTime(){
  return preparationTime;
}

int Recipe::getIngredientSize(){
  return ingredient.size();
}

std::vector<std::string> Recipe::getIngredient(){
  return ingredient;
}

std::vector<std::string> Recipe::getIngredientAmount(){
  return ingredientAmount;
}

std::vector<std::string> Recipe::getInstructions(){
  return instructions;
}
//Printers

void Recipe::printRecipeName(){
  std::cout << "Recipe Name: " << this->getRecipeName() << std::endl;
}

void Recipe::printCookingTime(){
  std::cout << "Cooking Time: " << cookingTime << std::endl;
}

void Recipe::printPreparationTime(){
  std::cout << "Preparation Time: " << preparationTime << std::endl;
}

void Recipe::printIngredients(){
  std::cout << "Printing ingredients\n";
  int count = 0;
  for (int i = 0; i < ingredient.size(); i++){
    std::cout << ingredient[i] << std::endl;
  }
  std::cout << std::endl;
}

void Recipe::printInstructions(){
  std::cout << "Printing instructions\n";
  for (int i = 0; i < instructions.size(); i++){
    std::cout << i + 1 << ". " << instructions[i] << std::endl;
  }
  std::cout << std::endl;
}
