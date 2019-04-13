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
  if (ingredient.back() == item){
    std::cout << "Pushed back: " << item << std::endl;
  }
}

void Recipe::addIngredientAmount(std::string amount){
  ingredientAmount.push_back(amount);
  if (ingredientAmount.back() == amount){
    std::cout << "Pushed back: " << amount << std::endl;
  }
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
  int count = 0;
  for (auto i = ingredient.begin(); i != ingredient.end(); i++){
    std::cout << "Loop: " << count << std::endl;
    std::cout << *i << std::endl;
    count++;
  }
  std::cout << std::endl;
}
