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
  Recipe* getCurrentRecipe();
  //Sort recipe by most frequent ingredients
  Recipe* findRecipe(std::string rName);
  void printRecipeNames();
  Recipe* findByIngredient(std::string ingr);

  void importRecipe(std::string rName);
  void importAll();
private:
  std::vector<Recipe> listRecipe;
  Recipe* current;
};
