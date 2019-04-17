#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

class Recipe
{
public:
//Declaration
  Recipe();
  Recipe(std::string name, int cTime, int pTime);

//setters
  void addIngredient(std::string item);
  void addIngredientAmount(std::string amount);
  void setRecipeName(std::string name);
  void setCookingTime(int cTime);
  void setPreparationTime(int pTime);
  void inputInstructions();
  //Sort ingredients by name

//getters
  std::string getRecipeName();
  int getCookingTime();
  int getPreparationTime();
  int getIngredientSize();
  std::vector<std::string> getIngredient();
  std::vector<std::string> getIngredientAmount();
  std::vector<std::string> getInstructions();

//printers
  void printRecipeName();
  void printCookingTime();
  void printPreparationTime();
  void printIngredients();
  void printInstructions();

private:
  std::vector<std::string> ingredient;
  std::vector<std::string> ingredientAmount;
  std::vector<std::string> instructions;
  int cookingTime;
  int preparationTime;
  std::string recipeName;
};
