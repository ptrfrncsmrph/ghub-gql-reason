let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let accessToken = "29b20cc5d89037171fab000ab4c5374e08372055";

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