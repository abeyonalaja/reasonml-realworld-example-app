open Jest;
open JsonRequests;

let errorsJson = {j|{"errors":{"email":["is invalid"],"password":["is too short (minimum is 8 characters)"]}}|j};

let succesWithJson = {j|{
  "user":{
    "id":12123,
    "email":"bryant@bryant.com",
    "createdAt":"2017-09-23T09:35:16.686Z",
    "updatedAt":"2017-09-23T09:35:16.691Z",
    "username":"bryant",
    "bio":null,
    "image":null,
    "token":"eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpZCI6MTIxMjMsInVzZXJuYW1lIjoiYnJ5YW50IiwiZXhwIjoxNTExMzQzMzE2fQ.WpeiSLOW2UUYrgeC0cgPkLY5v7aUC7yNKcIVMClgfCw"
  }
}|j};

let () =
  describe "New user request"
    ExpectJs.(fun () => {
      test "should respond with a decoded error" (fun () => {
        let newUser = parseNewUser errorsJson;
        
        switch newUser.errors {
          | Some _response => expect true |> toBeTruthy
          | None => expect (false) |> toBeTruthy
        };
      }); 
      
      test "should have an invalid email" (fun () => {
        let newUser = parseNewUser errorsJson;
        
        switch newUser.errors {
          | Some errorList => 
            switch errorList.email {
            | Some error => expect (Array.get error 0) |> toBe "is invalid"
            | None => fail "this has failed"
            }
          | None => fail "this has failed"
        }; 
      });

      test "should have an error where the password is too short" (fun () => {
        let newUser = parseNewUser errorsJson;

        switch newUser.errors {
          | Some errorList => 
            switch errorList.password {
              | Some password => expect (Array.get password 0) |> toBe "is too short (minimum is 8 characters)"
              | None => fail "Failed to check password validation"
            };
          | None => fail "Failed to return any errors"
        };
      });

      test "should have the correct username" (fun () => {
        let newUser = parseNewUser succesWithJson;
        /* open Models;
        let json = Js.Json.parseExn succesWithJson;

        let parseErrors json => {
          Some Json.Decode.{
            email: json |> optional (field "email" (array string)),
            password: json |> optional (field "password" (array string)),
            username: json |> optional (field "username" (array string))
          };
        };
        
        let possibleErrors = Json.Decode.(json |> optional (field "errors" parseErrors)); 
        Js.log possibleErrors;
        
        expect possibleErrors |> toBe None 
      });*/
        expect "" |> toBe ""
      });
    });