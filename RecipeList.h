#include "List.h"


class RecipeList
{
public:
//Declaration
  RecipeList();
//setters
  void addRecipe();
  void removeRecipe(std::string rName);
  void changeRecipe(std::string rName);
  void exportRecipe(std::string rName);
  void exportAll();

//getters
  int recipeAmount();
  bool listEmpty();
  bool findRecipe(std::string rName);
  Recipe* getCurrentRecipe();
  //Sort recipe by most frequent ingredients
  Recipe* getRecipe(std::string rName);
  void printRecipeNames();
  Recipe* findByIngredient(std::string ingr);
  void importRecipe(std::string rName);
  void importAll();
  void printRecipe(std::string rName);
  void randomRecipe();
private:
  std::vector<Recipe> listRecipe;
  Recipe* current;
};
