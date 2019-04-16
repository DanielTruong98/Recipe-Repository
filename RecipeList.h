#include "List.h"


class RecipeList
{
public:
//Declaration
  RecipeList();
//setters
  void addRecipe();
  void removeRecipe(std::string rName);
  void changeRecipe(int select);

//getters
  int recipeAmount();
  bool listEmpty();
  Recipe* getCurrentRecipe();
  //Sort recipe by most common ingredients
  Recipe* findRecipe(std::string rName);
  void printRecipeNames();
  Recipe* findByIngredient(std::string ingr);
private:
  std::vector<Recipe> listRecipe;
  Recipe* current;
};
