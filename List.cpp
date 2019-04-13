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
void Recipe::setRecipeName(std::string name){
  recipeName = name;
}

void Recipe::setCookingTime(int cTime){
  cookingTime = cTime;
}

void Recipe::setPreparationTime(int pTime){
  preparationTime = pTime;
}
//Getters
std::string Recipe::getRecipeName(){
  if (recipeName.empty()){
    std::cout << "Error: No recipe name\n";
    return "Error";
  }
  else{
    return recipeName;
  }
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

//Printers

void Recipe::printRecipeName(){
  std::cout << "Recipe Name: " << recipeName << std::endl;
}

void Recipe::printCookingTime(){
  std::cout << "Cooking Time: " << cookingTime << std::endl;
}

void Recipe::printPreparationTime(){
  std::cout << "Preparation Time: " << preparationTime << std::endl;
}

void Recipe::printIngredients(){
  std::cout << "Printing ingredients." << std::endl;
  for (auto i = ingredient.begin(); i != ingredient.end(); i++){
    std::cout << *i << std::endl;
  }
  std::cout << std::endl;
}
