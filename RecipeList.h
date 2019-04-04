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
  bool listFull();
  bool listEmpty();
  Recipe* getCurrentRecipe();
  int findCurrentSpot(int val);
  //Sort recipe by name
  //Search through recipes
  Recipe* findRecipe(std::string rName);
private:
  int currentplace;
  std::vector<Recipe> listRecipe;
  Recipe* front;
  Recipe* back;
  Recipe* current;
};
