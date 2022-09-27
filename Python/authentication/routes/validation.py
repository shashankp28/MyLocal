from fastapi import APIRouter, Depends
from datetime import timedelta
from fastapi import Depends, HTTPException, status
from fastapi.security import OAuth2PasswordRequestForm
from authentication.models.validation import Token
from authentication.controller.validation import (
    authenticate_user,
    create_access_token,
    ACCESS_TOKEN_EXPIRE_MINUTES,
)
from authentication.models.validation import User
from authentication.controller.validation import get_current_active_user


authenticate = APIRouter()


@authenticate.post("/token", response_model=Token, tags=["Authenticate User"])
async def login_for_access_token(form_data: OAuth2PasswordRequestForm = Depends()):
    user = authenticate_user(form_data.username, form_data.password)
    if not user:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Incorrect username or password",
            headers={"WWW-Authenticate": "Bearer"},
        )
    access_token_expires = timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)
    access_token = create_access_token(
        data={"sub": user.emailId}, expires_delta=access_token_expires
    )
    return {"access_token": access_token, "token_type": "bearer"}


@authenticate.get("/current-user/", response_model=User, tags=["Authenticate User"])
async def read_users_me(current_user: User = Depends(get_current_active_user)):
    return current_user


@authenticate.get("/current-user/email-id/", tags=["Authenticate User"])
async def read_own_items(current_user: User = Depends(get_current_active_user)):
    return [{"item_id": "Foo", "owner": current_user.emailId}]
