module Commits = [%graphql
  {|
  query Commits {
    user(login: "ptrfrncsmrph") {
      name
      contributionsCollection {
        commitContributionsByRepository {
          repository {
            name
            primaryLanguage {
              name
            }
          }
          contributions(first: 100) {
            pageInfo {
              hasNextPage
            }
            nodes {
              occurredAt
            }
          }
        }
      }
    }
  }
  |}
];

module CommitsQuery = ReasonApollo.CreateQuery(Commits);

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => {
    let commitsQuery = Commits.make();
    <div>
      <Text />
      <h1> {"githubub" |> ReasonReact.string} </h1>
      <CommitsQuery variables=commitsQuery##variables>
        ...{({result}) =>
          switch (result) {
          | Loading => <div> {"Loading..." |> ReasonReact.string} </div>
          | Error(error) =>
            <div> {error##message |> ReasonReact.string} </div>
          | Data(response) =>
            switch (response##user) {
            | None => <div> {"No user was found" |> ReasonReact.string} </div>
            | Some(user) =>
              <ul>
                {user##contributionsCollection##commitContributionsByRepository
                 |> Js_array.map(c =>
                      switch (c##contributions##nodes) {
                      | Some(nodes) =>
                        <ul>
                          {nodes
                           |> Js_array.map(n =>
                                <li>
                                  {(
                                     switch (n) {
                                     | None => "No date"
                                     | Some(n) =>
                                       n##occurredAt
                                       |> Js.Json.decodeString
                                       |> (
                                         res =>
                                           switch (res) {
                                           | None => "JSON parse failure"
                                           | Some(s) => s
                                           }
                                       )
                                     }
                                   )
                                   ++ " "
                                   ++ (
                                     switch (c##repository##primaryLanguage) {
                                     | None => "No primary language"
                                     | Some(l) => l##name
                                     }
                                   )
                                   |> ReasonReact.string}
                                </li>
                              )
                           |> ReasonReact.array}
                        </ul>
                      | None =>
                        <div> {"Couldn't fetch" |> ReasonReact.string} </div>
                      }
                    )
                 |> ReasonReact.array}
              </ul>
            }
          }
        }
      </CommitsQuery>
    </div>;
  },
};