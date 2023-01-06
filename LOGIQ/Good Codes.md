-   metacache.go:100 good way of closing files after creating and making changes to them.

Very good way of creating buffer for reading and writing a chunk (line :106 to :

```
defer func() {
	if errClose := fo.Close(); errClose != nil {
		errRet = errClose
	}
}()
```

