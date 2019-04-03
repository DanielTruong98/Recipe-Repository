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
  void addIngredientAmount(std::string amount);
  void setRecipeName(std::string name);
  void setCookingTime(int cTime);
  void setPreparationTime(int pTime);
  //Sort ingredients by name

//getters
  std::string getRecipeName();
  int getCookingTime();
  int getPreparationTime();
  int getIngredientSize();
  void printIngredients();
private:
  std::vector<std::string> ingredient;
  std::vector<std::string> ingredientAmount;
  int cookingTime;
  int preparationTime;
  std::string recipeName;
};
