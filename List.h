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
  void setCookingTime(int cTime);
  void setPreparationTime(int pTime);

//getters
  std::string getRecipeName();
  int getCookingTime();
  int getPreparationTime();
  int getIngredientSize();
  void printIngredients();
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

class RecipeList
{
public:
//Declaration
  RecipeList();
//setters
  void addRecipe(std::string rName);
  void removeRecipe(std::string rName);
  void changeRecipe(int select);

//getters
  int recipeAmount();
  bool listFull();
  bool listEmpty();
  //Search through recipes
private:
  std::vector<Recipe> listRecipe;
  Recipe* current;
  Recipe* nextRecipe;
  Recipe* previousRecipe;
};

//Declaration
RecipeList::RecipeList(){
  nextRecipe = NULL;
  previousRecipe = NULL;
  current = NULL;
}


//setters

//getters
int RecipeList::recipeAmount(){
  return listRecipe.size();
}
