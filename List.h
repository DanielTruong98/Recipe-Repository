#include <iostream>
#include <vector>
#include <string>

class Recipe
{
public:
//Declaration
  Recipe();
  Recipe(std::string name, int cTime, int pTime);

//setters
  void addIngredient(std::string item);
  void setRecipeName(std::string name);

//getters
  std::string getRecipeName();
  int getCookingTime();
  int getPreparationTime();
private:
  std::vector<std::string> ingredients;
  int cookingTime;
  int preparationTime;
  std::string recipeName;
};
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


class RecipeList
{
public:
  RecipeList();

private:
  std::vector<Recipe> listRecipe;
  Recipe* current;
  Recipe* nextRecipe;
  Recipe* previousRecipe;
};

RecipeList::RecipeList(){
  nextRecipe = NULL;
  previousRecipe = NULL;
  current = NULL;
}
