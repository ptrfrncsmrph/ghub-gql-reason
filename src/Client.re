let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let accessToken = "e711947b506957d760cf48b3c6f67c50dfed5334";

let contextHandler = () => {
  let headers = {
    "headers": {
      "authorization": {j|Bearer $accessToken|j},
    },
  };
  headers;
};

let authLink = ApolloLinks.createContextLink(contextHandler);

let httpLink =
  ApolloLinks.createHttpLink(~uri="https://api.github.com/graphql", ());

let instance =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.from([|authLink, httpLink|]),
    ~cache=inMemoryCache,
    (),
  );