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
  //Sort recipe by name
  Recipe* findRecipe(std::string rName);
  void printRecipeNames();
private:
  std::vector<Recipe> listRecipe;
  Recipe* current;
};
