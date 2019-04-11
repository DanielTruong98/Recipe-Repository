#include "List.h"

//Declaration
Recipe::Recipe(){
  cookingTime = 0;
  preparationTime = 0;
  recipeName = "";
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
  std::cout << "Recipe Name: " << recipeName << std::endl;
  return recipeName;
}

int Recipe::getCookingTime(){
  std::cout << "Cooking Time: " << cookingTime << std::endl;
  return cookingTime;
}

int Recipe::getPreparationTime(){
  std::cout << "Preparation Time: " << preparationTime << std::endl;
  return preparationTime;
}

int Recipe::getIngredientSize(){
  std::cout << "Amount of ingredients: " << ingredient.size() << std::endl;
  return ingredient.size();
}

void Recipe::printIngredients(){
  std::cout << "Printing ingredients." << std::endl;
  for (auto i = ingredient.begin(); i != ingredient.end(); i++){
    std::cout << *i << std::endl;
  }
  std::cout << std::endl;
}
