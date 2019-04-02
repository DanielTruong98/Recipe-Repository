#include "List.h"

//Declaration
Recipe::Recipe(){
  cookingTime = 0;
  preparationTime = 0;
  recipeName = "Unknown";
}
Recipe::Recipe(std::string name, int cTime, int pTime){
  recipeName = name;
  cookingTime = cTime;
  preparationTime = pTime;
}

//Setters
void Recipe::addIngredient(std::string item){
  ingredients.push_back(item);
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
  std::cout << "Amount of ingredients: " << ingredients.size() << std::endl;
  return ingredients.size();
}

void Recipe::printIngredients(){
  for (auto i = ingredients.begin(); i != ingredients.end(); i++){
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}
