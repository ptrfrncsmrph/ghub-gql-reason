let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

[@bs.val] external accessToken: string = "process.env.GH_TOKEN";

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